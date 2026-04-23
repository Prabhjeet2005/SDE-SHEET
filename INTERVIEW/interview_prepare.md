# Code how WRITE AI or SELF?
- I focus always on WHY and the HOW
- **I design the logic**
- For eg: I Know Websocket required for Real-time Proctoring over standard HTTP REST API, So when it comes to exact Implementation i refer to official Documentation & AI Assisted Tooling
- **RESULT:** Lead me to Fast Develop & Ship Features, But *Architectural Decisions & System Logc are entirely mine*



# HTTP v/s Websockets
## HTTP
1. Connection Open & Close for Every Request (constant polling -> Overloads server)
2. Unidirection Communication: Client Requests and Server Responds
3. Best For: Fetching static data

## Websockets
1. Stay Open constantly
2. Bidirectional Communication
3. Best For: Real-time data (e.g: Live video Proctoring)

**Why WEBSOCKET in PrepMasterAi**
- HTTP REST API like sending Text Message, Request -> Wait -> Response, If i need to know an update i need to make request again and if every second i need the update i make 60 Requests a Minute **(POLLING)** which crushes Server Performance

- WEBSOCKET like Phone Call: I call server -> Pickup [HANDSHAKE] -> Connection remain open -> Server can push data [like video frame or warning] instantly to CLIENT without it ever asking for it

**WebSocket Pseudo-Code**
`socket.emit('video_frame', data)` -> Client sends.
`socket.on('anomaly_detected', () => { ... })` -> Client listens.


# Node.js Streams (Bottleneck)
**Concept:** Drinking 10L Water all at once -> Drink glass by glass
**Application:** 
- **PROBLEM:** Read 5Gb Postgresql db backup into Node.js with standard method into computer RAM -> Server Crash 
- **Solution:** Stream break 5Gb file into tiny chunks(buffers), reads chunk, compresses it, encrypts it and sends it out then move to next chunk, [Thus saving precious RAM regardless of size of file]

# State Management: React Reducers
- **useState():** Simple state
- **useReducer():** Complex and many states, REDUCER -> Centralized function, We send *Actions* ('UPDATE_PRICE' or 'SELECT_DATE') and Reducer calculates exact new state


# JWT Authentication
**JWT:** JSON Web Token - stateless authentication method
**WORKING:** LogIn -> server verify password -> give signed JWT -> Browser Cookies store data -> Every Request this token attached (Server just verify signature using SECRET_KEY not DB lookup everytime) making it *[Fast & Secure]*


# PrepMasterAi [Project 1]

## PROJECT Overview *[Architectural Decisions]*

### Phase 1: The Architectural Journey (How it evolved)

If they ask, *"Walk me through how you built this"* here is the logical progression you should describe:

1.  **The Foundation (MERN + Socket.io):** tarted with a standard MERN stack (MongoDB, Express, React, Node.js) to handle user authentication and basic database storage.
2.  **The Video Bottleneck (Edge Processing):** Initially, sending live video from the client to the server for AI analysis would crash the server or cause massive lag. Your biggest architectural decision was shifting the video processing to the **Client Edge** (running the detection locally on the browser) and only sending lightweight text warnings (e.g., "Multiple faces detected") to the server.
3.  **The Audio Pipeline (Deepgram):** With video solved, you needed a way to process speech for the mock interview. You integrated Deepgram's SDK for real-time, fault-tolerant audio streaming, ensuring that words weren't lost if the connection blinked for a millisecond.
4.  **The AI Brain (Gemini/Groq):** You routed the transcribed text to Groq/Gemini APIs to act as the interviewer, parsing the user's answers and generating dynamic follow-up questions.
5.  **Storage Optimization (Cloudinary + MongoDB):** Finally, you needed to save proof of cheating. Storing massive Base64 image strings directly in MongoDB made the database incredibly slow. You fixed this by intercepting the images, uploading them to Cloudinary (object storage), and only saving the short image URL in MongoDB.
  - *Why BASE64 Image Bad Idea in MongoDB?* 
    - Original Size + 30% increase
    - MongoDb 16MB per Document, multiple Images can easily exceed this limit
    - Performance Decrease, Extra CPU compute

---

### Phase 2: The Core Interview Topics (Your Hitlist)

To make your project bulletproof, we need to deeply understand the mechanics behind these five pillars. I will keep the code examples purely text-based and straightforward so they are easy to visualize and explain without getting bogged down in complex visualizers.

* **Topic 1: Dual-Device Synchronization (WebSockets/Rooms):** How you paired a specific mobile phone to a specific laptop without them sending data to the wrong user.
* **Topic 2: Client-Edge Video Processing:** Defending the decision to do AI processing on the user's device instead of your backend server.
* **Mobile Choke**
* **Topic 3: The AI Interview Engine:** How you managed state and context so Gemini/Groq actually "remembered" the ongoing conversation instead of treating every answer as a new chat.
* **Topic 4: Database Payload Optimization:** The exact mechanics of the Cloudinary to MongoDB pipeline and why Base64 strings are a database killer.
* **Topic 5: No-Loss Audio Pipeline:** How packet-buffering queues prevent data loss during WebSocket handshakes.


---
**Topic 1: Dual Device Synchronization**  `socketHandler.js`

**Challenge:** 5 Student Laptop + 5 Student Mobile, Correctly give penalty to correct person

**Solution:** Socket.io *Rooms* feature, generated unique *RoomId*, when Laptop connects joins a room when User scans QR Code from phone, it also join same *RoomId*

**My Approach:** Node.js as pure traffic Controller, it doesn't process video just handle communication (Room) and ensure message forward back and forth b/w Laptop and Mobile



---
**Topic 2: Client Side Video Processing**

**Challenge :** Multiple Device Massive Server Load + Lag enable Cheating possibility + Privacy User

**Solution:** Downloaded AI Models (Tensorflow.js, COCO-SSD, Face-Api) directly into user's browser memory when test starts, Browser's own GPU analyze webcam Locally, Server only receives Text Alerts via WEBSOCKETS
---

**Topic: Mobile Choke**

**Challenge:** scan mobile video feed every 3 seconds, Older Phones Completely Freeze and crash after few mins, Issue in JavaScript event Loop, if older phone take 4 seconds to process Heavy Ai Models, `setInterval` didn't care it fired again after 3 seconds anyway, then CPU load and Phone Freezed

**Solution:** I abandoned `setInterval` instead i used setTimeout(), ensuring next scan take place when current FINISHED, Random Delay from 3 to 7 Seconds, next scan will never fire before completing current scan [Give Rest to Mobile CPU]
 

---
**Topic 3: No Loss Audio**  `socketHandle.js`

**Challenge:** User click *Start Interview* browser capture Mic, Establishing WebSocket Handshake takes around 200-250 ms, User Speak Immediately -> Data Loss  *[RACE CONDITION: audio races connection setup of Deepgram]*

**Solution:** In Memory Buffering Queue, Audio Arrives while DEEPGRAM **readyState === 0** then push data chunk to array, when deepgram opens iterate through Queue and send all packets to AI ensuring No speech Loss and after all speech we hit "DONE" to send to LLM 

---

---
**Topic 4: Ai Interview Engine**  `aiService.js`

- Topics: 
* 1. STATE/MEMORY Management: Ai remember prev Ques of User [REST API stateless]
* 2. Prompt Engineering Security: How stop Ai from Hallucinating/Breaking Character
* 3. Latency: Why User don't wait for 10 seconds for reply

**Challenge:** [Move From Standard ChatBot] Standard Rest API stateless, Ai Forgets the Interaction between Question and Answer

**Solution:** In memory Sessions Object (holds Entire Chat History: System_Prompt, Ai_Question, User_Answers) for interview, Every Time User Speak send entire array to API forcing **AI** to read whole context before Reply, Atlast i store entire message to MongoDB For Access Later

**Challenge 2:** How Ai not Break Character?

**Solution:** In LLM {role:"system"} holds highest authority over {role:"user"} Inputs

**Challenge 3:** Latency Less?

**Solution:** In memory chat history `this.sessions` reading from Local RAM faster

---


---
**Topic 5: Database Payload Optimization**

**Challenge:** Ai Detect Cheating Draw Box and store in Base64 -> MongoDB Document Limit 16 MB exhaust

**Solution:** Only URL saved from Cloudinary
---



- The React client continuously emits video frames over the WebSocket, while actively listening on an 'anomaly_detected' channel. 
- The Node.js server listens for those frames, processes them, and if cheating is detected, it instantly emits the anomaly event back to the client, triggering a real-time UI alert without the client ever needing to ask for an update.

**SERVER Websocket**
```
// 1. A client connects to the server
io.on('connection', (socket) => {
    console.log('A student connected for proctoring');

    // 2. SERVER LISTENS for video frames coming from the client
    socket.on('video_frame', (data) => {
        
        // (Pretend we run our AI check on the 'data' here)
        const isCheating = true; 

        if (isCheating) {
            // 3. SERVER SPEAKS, sending a warning back to that specific client
            socket.emit('anomaly_detected', 'Multiple faces detected!');
        }
    });
});
```

**CLIENT Websocket**
```
// 1. Client dials the server to open the connection
const socket = io('http://localhost:5000');

// 2. CLIENT SPEAKS, sending webcam data to the server
function sendVideoToAI(webcamData) {
    socket.emit('video_frame', webcamData);
}

// 3. CLIENT LISTENS for any warnings pushed by the server
socket.on('anomaly_detected', (warningMessage) => {
    // If the server emits this event, this code instantly runs
    alert("Warning: " + warningMessage);
});
```






