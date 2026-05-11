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

# SYSTEM DESIGN

**Low-Level Design (LLD) - High Priority**

* OOP Fundamentals: Classes, Polymorphism, Encapsulation, Abstraction.
* SOLID Principles: (Covered above).
* Design Patterns: Singleton, Factory, and Observer (event listeners).
* Schema Design: How to design the database tables for a simple app (e.g., "Design the tables for a library system").

**High-Level Design (HLD) - Medium Priority**

* Client-Server Architecture: How a frontend talks to a backend.
* Communication Protocols: REST APIs vs. WebSockets (You already know this deeply from your proctoring project!).
* Databases: SQL (Relational, ACID) vs. NoSQL (Document, Flexible).
* Scaling Basics: Vertical Scaling (buying a bigger server) vs. Horizontal Scaling (adding more servers).
* Load Balancing: What happens when 10,000 users hit your app at once.

## OOP (SOLID, Design Patterns[Singleton, Factory])

### SOLID Principles

**S - Single Responsibility Principle:** A class should do only one thing 
* (e.g.Don't make a Robot class that cooks, paints, and does math. Create ChefRobot and PainterRobot.).

**O - Open/Closed Principle (OCP):** Code should be open for extension (adding new features via inheritance) but closed for modification (not altering existing, tested code).

**L - Liskov Substitution Principle (LSP):** You should be able to replace parent class with its child class without breaking the application. (e.g., If Bird has a fly() method, Penguin shouldn't inherit from Bird).

**I - Interface Segregation Principle (ISP):** Do not force a class to implement functions it does not need. Keep interfaces or (abstract classes) small and specific.

**D - Dependency Inversion Principle (DIP):** High-level modules should depend on abstractions (interfaces), not on concrete, low-level details. (e.g: Robot should not depend on DuracellBattery, it should Require Battery Interface and if i invent SolarBattery tomorrow then Robot accepts it without changing any code)


### DESIGN PATTERNS [Singleton, Factory]

**Singleton Pattern:** 
* Ensure Class has ONE instance globally. (e.g: One DB Connection for whole app)
* *HOW:* Make Constructor Private so no one can use `new`. Give `static` function to be shared by everyone

```
class Database {
private:
    // Private constructor: No one can say "Database db;"
    Database() {} 

public:
    // Static means this function belongs to the class itself, not an object
    static Database* getInstance() {
        static Database shared_instance; // Created only once, lives forever
        return &shared_instance;
    }

    void query(string q) {
        cout << "Running: " << q << endl;
    }
};

int main() {
    // We just ask the class for the shared pointer
    Database* db = Database::getInstance();
    db->query("SELECT * FROM users");
}
```

**Factory Pattern** 
* Centralized class creating other objects based on Input (e.g: Enemy Spawn Based on Levels)

```
#include<iostream>
using namespace std;

class Enemy{
  public:
  // Pure Virtual Function
  virtual void attack() = 0;
};

class Zombie: public Enemy{
  public:
  void attack() override{
    cout<<"Zombie is Attacking\n";
  }
};

class Vampire: public Enemy{
  public:
  void attack() override{
    cout<<"Vampire is attacking\n";
  }
};

class EnemySpawn{
  public:
  static Enemy* spawn_enemy(int type){
    if(type == 1)return new Zombie();
    if(type == 2)return new Vampire();
    return nullptr;
  }
};

int main(){
    // Avoid many if/else statements, Enemy* because it is parent class and can incorporate many different Enemies
  Enemy* e = EnemySpawn::spawn_enemy(2);    
  e->attack();
}
```

---

# DBMS

## The Ultimate DBMS Interview Blueprint

**Chunk 1: Relational Fundamentals (The Core Theory)**  `ONLY THEORY`
*   **Keys & Constraints:** Primary Key vs. Unique Key, Foreign Keys.
*   **Data Integrity:** The ACID Properties (Atomicity, Consistency, Isolation, Durability).
*   **Database Design:** Normalization (1NF, 2NF, 3NF, BCNF) and when to use Denormalization.

**Chunk 2: SQL Execution & Aggregation (The Basics)** `CODING REQUIRED`
*   **The SQL Engine:** Query Execution Order (How the database reads your query vs. how you write it).
*   **Basic Filtering:** The `LIKE` operator, `IN`, and `BETWEEN`.
*   **Summarizing Data:** `GROUP BY` + Aggregate Functions (`COUNT`, `SUM`, `MAX`, `MIN`).
*   **Filtering Groups:** `HAVING` vs. `WHERE` (e.g., *Query: Each state having a male count > 10,000*).

**Chunk 3: Relational Data Mapping (Connecting Tables)** `CODING REQUIRED`
*   **The Joins:** Inner, Left, Right, Full Outer, and the highly-tested Self-Join.
*   **Nested Logic:** Subqueries (Correlated vs. Uncorrelated).
*   **Clean Code:** Common Table Expressions (CTEs / the `WITH` clause).

**Chunk 4: Advanced SQL (The MAANG Favorites)** `CODING REQUIRED`
*   **Window Functions Overview:** What the `OVER()` and `PARTITION BY` clauses do.
*   **Ranking:** `ROW_NUMBER()` vs. `RANK()` vs. `DENSE_RANK()`.
*   **Classic Whiteboard Queries:** Finding the 2nd Highest Salary, Nth Highest Salary, and finding the top performer per department.

**Chunk 5: Performance & Architecture (The Senior Level)**  `ONLY THEORY`
*   **Fast Retrieval:** Indexing (How B-Trees work, Clustered vs. Non-Clustered Indexes).
*   **Query Optimization:** How to tune slow queries, reading Execution Plans, and why `SELECT *` is bad.
*   **Concurrency:** Isolation Levels (Read Committed, Repeatable Read, Serializable) and handling Deadlocks.

---

### CHUNK 1 `[THEORY ONLY]`

**KEYWORDS:**
* `Row Operations:` Like Add/Subtract from 2 Rows trick SQL by Using `JOIN` and get data in Same Row
* `LENGTH(col_name)`
* `IS NULL, IS NOT NULL`
* `!=` -> Not Equal to
* `SELF JOIN:` Use When **ROWS Depend On Each Other**
* `Single Table + GROUP BY:` Rows Don't Depend on Each Other and Squash multiple Rows like into Department
* `LEFT JOIN` -> Keep all Data from Left Table
* `ROUND(some_calc,2)` -> Rounds to 2 Decimal Place
* `SUM(condn_or_columnName)` -> Sums all rows satisfying condition
* `DATEDIFF(today,yesterday) = 1` -> Date Difference of 1
* Multiple `ON` Conditions: it allows to bucket according to Student name and specific Exam (LEETCODE 1280)
* `ONLY_FULL_GROUP_BY: [IMPORTANT]` If Column in SELECT statement, then it must be under AGGREGATE Function or it must be in Group By {MEANS: everything in SELECT query must be either in aggregate function or in GROUP BY}
* `IFNULL(some_calculation,0)` Fills Null with 0 and add SAFETY CHECK
* `AVG(rating/position) [IMPORTANT]` Here Inner Math On Each Row FIRST rating/position done then take average of those Calculations of each row 
  * Eg: Row 1: rating/position, Row 2: rating/position then After All Row Operation done Calculate Avg (Row1 + Row2)/ Total Count
  * **First generate Answer for Each Row, then apply average on the calculation sum / TOTAL**

* `How to solve Row Calculations Using Joins?: [IF, CASE WHEN THEN ELSE END]` 
  * **STEP 1:** Use LEFT JOIN
  * **STEP 2:** Use Group By
  * **STEP 3:** Use `IF` or `CASE WHEN` where all true are 1 and else they are 0
  * `AVG(IF(c.action = 'confirmed',true_value,false_value))`
  * `CASE WHEN THEN ELSE END`
    * ```
      SELECT Order_id,
        CASE 
          WHEN Price < 20 THEN 'Low Cost'
          WHEN Price BETWEEN 20 AND 40 THEN 'Medium Cost'
          ELSE 'High Cost'
        END AS PriceCategory
      FROM Products;
      ```


**LIKE**
* `%` Matches Rest 
* `_` Matches Exactly Once

```
SELECT *
From table
WHERE name LIKE 'a%'    -- STARTS WITH a Apple
  OR name LIKE '%a_'    -- Last Second Character a
```

**PRIMARY KEY**

* Uniquely identify row in table 
* Only 1 Primary Key Per Table
* Can't have NULL values
* Eg: `Aadhar Number` -> Primary Key,

**UNIQUE KEY**

* Ensure Specific Column Values are all different
* Can Accept multiple NULL Values
* Multiple Column can have Unique Keys
* Eg: `Phone Number`(Can't have phone or if have then unique) -> Unique Key

**FOREIGN KEY**

* Column in one table linking to Primary Key of another table
* Helps maintain `REFERENTIAL INTEGRITY`. [Can't add new Order without user_id existing in Users Table]

---
**ACID Properties [DataBase MySQL Automatically Handle]**

**Atomicity (All or Nothing)**

* Transaction is single unit, either complete fully or rollbacked to never started
* Eg: transfer $1000 from my account debited but before crediting to another account, server crashes then Entire Transaction Rollbacks.

**Consistency (Follow the Rules)**

* Database must remain in valid state
* If Column has strict constraint like (balance >= 0), if transaction that drops below 0 will be rejected instantly.

**Isolation (Wait Your Turn)**

* If 2 user book exact movie ticket at exact same millisecond, then database handles them `sequentially`
* One transaction completely isolated from other until it finishes.

**Durability (Saved Forever)**

* Once Transaction Successful, data written to Disk and must still be there if Server Restarts.

---

**NORMALIZATION**

Normalization is Process of organizing data to reduce redundance(data duplication) and prevent data corruption when inserting, updating or deleting records.

**1st Normal Form** 

* Single Cell, Single Value
* If multiple like [Python,Java] break into multiple rows

**2nd Normal Form [Partial Dependency]**

* If Composite Key(Primary Key 2 or more cols), then all other Columns [Non-Key] depend on Entire Key not just a part of it
* Eg: Student_ID (PK) | Course_ID (PK) | Student_Name | Course_Name 
  * Here, Name like "Prabhjeet" only depends on Student_ID regardless of maths or english (i.e part of composite key)
  * `PROBLEM:` Prabhjeet takes 5 courses, name is typed 5 times in database, name changes then update 5 rows
  * `SOLUTION:` Pull Student_Name and make Students table, Courses Tables and Enrollment Table


**3rd Normal Form [No Transitive Dependency]**

* Must be in 2nd Normal Form
* Non Key Column shouldn't depend on another Non Key Column eg: A(PK)->B->C
* Eg: Course_ID(PK) | Course_Name | Professor_Name | Professor_Email
  * `PROBLEM:` Here Professor_Email Depends on Professor_Name, So if they teach 5 different course then their Email saved 5 different Times
  * `SOLUTION:` Pull professor details into Professor table

**BCNF**

* Stricter version of 3rd Normal Form
* States that for every dependency A->B (A i.e Determinant) must be Candidate Key
* A(PK) -> B where A must be Primary Key who Controls (B shouldn't Control)
* Eg: single professor teach single course and course_id is Primary Key then Professor dictates Course but Professor not primary Key, So make new table for Professor where they are Primary Key


**Normalization V/S Denormalization**

* `Read Heavy (Speed Priority):` Use Denormalization(Make Redundant Data) because Complex JOIN Queries take Time, 
  * eg `Twitter` Post -> Match Author, Profile_Pic and Tweet then JOIN very slow and Massive Lag

* `Write Heavy (Save Disk space | Prevent Data Anamoly ):` Normalization prefer because user name change one place then update everywhere, 
  * eg: `Banking system or E-Commerce Checkout` If user change Address then Update at one place not 1000's of rows in Orders Table

`NOTE:` **For 2NF: Check each column depend upon ENTIRE PK and can be Uniquely identified by single column of Composite Primary Key, For 3NF: Check Non Key on Non Key Dependency**


**QUESTIONS PRACTICE `NORMALIZATION`**

This is the perfect mindset for MAANG preparation. You don't get good at Database Design by reading; you get good by doing. 

I have designed three realistic scenarios based on actual tech company domains (Streaming, Ride-Sharing, and HealthTech). They progressively get a little trickier. 

For each scenario, read the business rules, look at the messy table, and reply with how you would break it down into perfectly normalized tables (up to 3NF). 

Take them one by one, or do all three at once. Let's see what you've got!

---

#### Practice Question 1: The Streaming Service (Netflix/Prime)
**The Scenario:** You are tracking every time a user watches a movie. The junior engineer created a massive table with a **Composite Primary Key: `(User_ID + Movie_ID)`**.

**Business Rules:**
* A user has a specific email and is subscribed to one specific plan.
* Each plan has a set monthly price.
* A movie has a specific title and a primary director.

**The Messy Table (1NF):**
| User_ID (PK) | Movie_ID (PK) | User_Email | Plan_Name | Plan_Price | Movie_Title | Director_Name | Watch_Date |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| U1 | M10 | p@mail.com | Premium | $15 | Inception | Nolan | 2026-05-01 |
| U1 | M22 | p@mail.com | Premium | $15 | Avatar | Cameron | 2026-05-02 |
| U2 | M10 | a@mail.com | Basic | $9 | Inception | Nolan | 2026-05-02 |

**Your Task:** Break this into 3NF. Watch out for partial dependencies (2NF) and transitive dependencies (3NF).

**`ANSWER`**

* For 2nf i analyzed every column and found in table only watch date depend upon both userid and movieid so in 2NF Table1: User_id(PK), Movie_id(PK), Watch_Date Table2: User_id(pk), email, Plan_name, Plan_price Table3: Movie_id, Movie_title, Director_name

* For 3NF i analyzed that Plan_price depends upon Plan_name so i updated table2: User_id(pk), email, Plan_name(fk) and create Table4: Plan_Name(PK), Plan_Price

---

#### Practice Question 2: The Ride-Sharing App (Uber/Lyft)
**The Scenario:** You are storing completed rides. This table uses a **Single Primary Key: `Ride_ID`**. 
*(Hint: Since it's a single-column primary key, there are NO partial dependencies. This table is already in 2NF! Your only job is to find the transitive dependencies to reach 3NF).*

**Business Rules:**
* A ride is driven by one specific driver.
* A driver has a specific name and drives one specific car.
* A car has a specific model (e.g., Honda Civic).

**The Messy Table (2NF):**
| Ride_ID (PK) | Ride_Date | Fare | Driver_ID | Driver_Name | Car_License_Plate | Car_Model |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| R900 | 2026-05-01 | $20 | D5 | John | ABC-123 | Honda Civic |
| R901 | 2026-05-01 | $15 | D8 | Sarah | XYZ-999 | Toyota Prius |
| R902 | 2026-05-02 | $30 | D5 | John | ABC-123 | Honda Civic |

**Your Task:** Break this into 3NF. What data relies on the Driver instead of the Ride? What data relies on the Car instead of the Driver?

**`ANSWER`**

* Table1: Ride_id(PK), Ride_Date, Fare, Driver_ID(FK)
* Table2: Driver_Id(PK), Driver_Name, Car_plate(FK)
* Table3: Car_Plate(PK), Car_Model


---

#### Practice Question 3: The HealthTech Clinic (The Boss Level)
**The Scenario:** You are booking patient appointments. The table uses a **Composite Primary Key: `(Patient_ID + Appointment_Date)`**. 

**Business Rules:**
* A patient has a specific name and phone number.
* An appointment is handled by one specific doctor.
* A doctor works at one specific clinic branch.
* A clinic branch has one specific physical address.

**The Messy Table (1NF):**
| Patient_ID (PK) | Appt_Date (PK) | Patient_Name | Patient_Phone | Doctor_ID | Doctor_Name | Clinic_Branch | Branch_Address |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| P1 | 2026-05-01 | Prabhjeet | 555-0101 | Doc_A | Dr. Smith | North Wing | 123 Main St |
| P1 | 2026-05-15 | Prabhjeet | 555-0101 | Doc_B | Dr. Jones | South Wing | 456 Oak St |
| P2 | 2026-05-01 | Amit | 555-0202 | Doc_A | Dr. Smith | North Wing | 123 Main St |

**Your Task:** Break this into 3NF. This one has partial dependencies AND a chain of transitive dependencies. How many tables do you need to make this perfectly clean? 

**`ANSWER 3NF`**

*NOTE: Doctor Can't exist solely on Appointment_date or Patient_ID*

* 1. Patients Table (You got this right!)
  *   `Patient_ID` (PK)
  *   `Patient_Name`
  *   `Patient_Phone`

* 2. Appointments Table (The original table, stripped down)
  *   `Patient_ID` (PK / FK)
  *   `Appt_Date` (PK)
  *   `Doctor_ID` (FK) *(The payload: This specific doctor is seeing this specific patient on this specific date).*

* 3. Doctors Table (You identified this transitive dependency!)
  *   `Doctor_ID` (PK)
  *   `Doctor_Name`
  *   `Clinic_Branch` (FK) *(The doctor works at a specific branch).*

* 4. Clinics Table (You identified this transitive dependency too!)**
  *   `Clinic_Branch` (PK)
  *   `Branch_Address`


---

Take your time. Reply with your proposed tables and the columns for each scenario (like you did for the E-commerce one), and I will evaluate them like a strict MAANG interviewer!


### CHUNK 2 [`SQL`]

**SQL Execution Ordering** 
* `FROM | JOIN -> WHERE -> GROUP BY -> HAVING -> SELECT -> ORDER BY -> LIMIT`

**SQL Execution Ordering `IMPORTANCE`**
* Alias Trap + Performance
* **ALIAS TRAP:** 
  ```SELECT 
    Salary * 12 AS Annual_Pay 
    FROM Employees
    WHERE Annual_Pay > 100000;
  ```
  * FROM -> WHERE -> GROUP BY -> HAVING -> SELECT -> ORDER BY -> LIMIT
  * WHERE Annual_Pay is ALIAS not yet being declared by Execution Engine so gives Error, So WHERE happens before SELECT so No Alias Present and Error take place

* **PERFORMANCE WHERE v/s HAVING**
  * Suppose 10 Million Rows
    * WHERE: Filters junk out first before any Heavy calculation
    * HAVING: Group all 10 Million rows first then it will apply maths

**WHERE v/s HAVING**
* `WHERE:` Filter out individual rows before grouping or math happens
* `HAVING:` Filter Grouped Records after math has been done

**SQL QUERY: Each state having Number of Males more than 10,000**

* Given: Census Table and Columns: State, Gender, Population 

```
SELECT state, SUM(population) FROM Census
WHERE gender = 'Male'
GROUP BY state
HAVING SUM(population) > 10000;
```

**JOINS**

**1. INNER JOIN**

* Matches `Common` Entries from Left and Right Table Only
```
SELECT * from table1
INNER JOIN table2
ON table1.id = table2.id;
```

**2. LEFT JOIN**

* Matches `ALL LEFT` + `MATCHING RIGHT` Entries Only
```
SELECT * 
FROM table1
LEFT JOIN table2
ON table1.id = table2.id;
```

**3. SELF JOIN `[V.IMP]`**

* It is `INNER JOIN` or `LEFT JOIN`, Where join Table to Copy of itself
* Use When `Hierarchial Data [like Manager and Employee]` Stored in One table
* Requires `ALIAS` otherwise Database Engine throw Ambiguity ERROR

* **`[IMPORTANT] Given Employees Table with Emp_id, Name, Salary, Manager_id. Write Query to find all employees who earn more than their Manager.`**

**The Table:**
| Emp_ID | Name | Salary | Manager_ID |
| :--- | :--- | :--- | :--- |
| 1 | Bossman | $200,000 | NULL |
| 2 | Prabhjeet| $250,000 | 1 |
| 3 | Amit | $150,000 | 1 |

**The Logic:**
You have to pretend there are two tables: A `Worker` table and a `Manager` table. 
We join the `Worker`'s `Manager_ID` to the `Manager`'s `Emp_ID`.


```
SELECT Workers.name
FROM Employees AS Workers
INNER JOIN Employees AS Managers
ON Workers.Manager_ID = Managers.Emp_ID
WHERE Workers.Salary > Managers.Salary;
```

**4. Natural JOIN [NEVER USE DANGEROUS]**

* Join Automatically based on `columns with Same Name`, No need to Write `ON` Clause
* `DANGEROUS:` If column is `Created_at` then Natural Join tries joining and Query breaks or return 0 results

```
SELECT * FROM Employees
NATURAL JOIN Departments;
```

**5. Full Outer JOIN**

* No OUTER JOIN in MySQL, so use LEFT JOIN *UNION* RIGHT JOIN
* Return every Row from both tables, 
  * Matches -> Links Them
  * Not Match -> Missing Side Fill NULL
* **PREFER:** Find missing Records both sides or Discrepencies
* **CAUTION:** Very Heavy on Database, 2 tables million rows spike Server CPU

* Most Commonly Used: Database Anamoly,` Write Query to find All Anaomalies: Employees who are missing department and Departments with 0 Employees`

```
SELECT Employee.name,Employee.department_name
FROM Employee 
LEFT JOIN Department ON Employee.dept_id = Department.dept_id
WHERE Department.dept_id IS NULL
UNION ALL
SELECT Employee.name,Employee.department_name
FROM Employee 
RIGHT JOIN Department ON Employee.dept_id = Department.dept_id
WHERE Employee.dept_id IS NULL;
```

**6. CROSS JOIN**

* Every single Row Table 1 match Every Single Row Table 2
* **PREFER:** Generate Combinations, grid or calendar table
* **CAUTION:** Cross Join Table1 with 1000 rows and table2 with 10,000 rows will CRASH DATABASE as total Rows is 10,000,000
* Most Commonly Asked: Building e-commerce store, Table1 -> "Colors" and Table2 -> "Sizes", Write Query to generate every possible variation of new Tshirt

```
SELECT * FROM colors
CROSS JOIN sizes;
```

### The Ultimate SQL Join Cheat Sheet

Here is your concise comparison table highlighting exactly when to use each join and the associated risks.

| Join Type | How it Works | Prefer When... | Caution / Look Out For |
| --- | --- | --- | --- |
| **INNER JOIN** | Strict match only. | You only want valid, complete records (e.g., Users who have actually placed an order). | Accidental data loss. If a valid user has a `NULL` order, they disappear from the results entirely. |
| **LEFT JOIN** | Keeps all left, matches right. | You need to preserve a base table while fetching optional data (e.g., All users, plus their orders if they have any). | Filtering on the right table in the `WHERE` clause can accidentally turn it into an `INNER JOIN`. |
| **RIGHT JOIN** | Keeps all right, matches left. | Virtually never. | Readability. It forces engineers to read queries backward. Just swap the table order and use `LEFT JOIN`. |
| **FULL OUTER** | Keeps absolutely everything. | Auditing data migrations, finding mismatched or orphaned records in both tables. | High performance cost. Do not use for standard application feature retrieval. |
| **SELF JOIN** | Joins a table to itself. | Dealing with hierarchical data (Managers/Employees) or comparing rows within the same table. | Requires aliases (e.g., `Table T1`, `Table T2`), otherwise the database engine throws an ambiguity error. |
| **CROSS JOIN** | Multiplies every row by every row. | Generating combinations (Sizes x Colors) or filling gaps in reporting dates. | Exponential row explosion. Can easily take down a database server if applied to large tables. |
| **NATURAL JOIN** | Implicitly joins identical column names. | Textbook exercises. | **Strictly avoid.** Silent failures if schema changes. Always explicitly define conditions with `ON`. |


### SUBQUERIES 

**PURPOSE:** Sometimes can't directly write `WHERE` because don't know Exact Value yet, EG: Find employee with Highest salary, Then can't write WHERE Salary = 1000 because don't know yet, So write another SUBQUERY to calculate max salary then feed into main query

**TYPE 1: Uncorrelated SubQuery**
* Inner Query Independent of Outer Query
* Eg: `Find Employees who make more than company average`

```
SELECT Name, Salary FROM Employees
WHERE Salary > (
  SELECT AVG(Salary) FROM Employees 
);
```


**TYPE 2: Correlated SubQuery**
* It is the Looper
* Inner Query execute over and over for every single row in Outer Table
* Eg: Find employees who make more than average salary of their specific department

```
SELECT Outer.Name, Outer.Salary
FROM Employees AS Outer
WHERE Outer.Salary > (
  SELECT AVG(Inner.Salary) 
  FROM Employees AS Inner
  WHERE Outer.dept_id = Inner.dept_id
);
```

**TRAPS: `=` v/s `IN`**

* If Subquery Returns Multiple Rows then use `IN` Operator
* Eg: `WHERE Dept_id IN (SELECT Dept_id FROM Departments WHERE location = 'Delhi');`


**MOST ASKED Question [SUBQUERY]**
* Find names of all Departments currently having 0 employees. Solve using Subquery, Not Using Join, you have Departments and Employees table

```
SELECT Name
FROM Departments
WHERE Dept_ID NOT IN (
  SELECT DISTINCT Dept_ID FROM Employees
  WHERE Dept_ID IS NOT NULL
);
```

**SubQuery v/s CTE(Common Table Expressions)**
* CTE makes it more readable
* CTE moves Inner Subquery to TOP using the `WITH` Keyword
* `CTE creates a Virtual Table`

```
WITH ActiveDepartments AS (
  SELECT DISTINCT Dept_ID FROM Employees 
  WHERE Dept_ID IS NOT NULL
)

SELECT Name
FROM Departments
WHERE Dept_ID NOT IN (Select Dept_ID FROM ActiveDepartments);
```

---

### Chunk 4: Window Functions & Ranking `[V.Imp MAANG 99% Chance]`

`NOTE:` Always Write Window Functions using `WITH`, because DataBase Engine execute them at `SELECT` 

**`WINDOW FUNCTION` GROUP BY v/s PARTITION BY**

* **WINDOW FUNCTION:** perform calculation across set of related rows without squashing them into single grouped Row

* **GROUP BY:** Group by Department then all Employees Squished into single Row per Department (Losing Individual Name)
* **PARTITION BY:** Doesn't Collapse Data(Keeps Rows Intact),PARTITION BY is Window Version of GROUP BY

* **SYNTAX:** `DENSE_RANK() OVER(PARTITION BY column ORDER BY column) AS alias_name`
  * **PARTITION BY:** Groups Data into Chunks of Departments


**RANKINGS**
* **ROW_NUMBER()** 1,2,3,4 doesn't skip strictly Sequential, Useful for Guaranteed Unique Id for Every Row
* **RANK()** 1,1,3,4 It skips Rank for Ties
* **DENSE_RANK() `PREFERRED`** 1,1,2,3 Doesn't Skip Rank for Ties

**LAG/LEAD**
* **LAG():** Looks backward to previous Row (If First row then give NULL)
  * `SYNTAX:` LAG(Amount) OVER (PARTITION BY Account_ID ORDER BY Date)
* **LEAD():** Looks forward to next Row


**MOST ASKED MAANG [`V.IMP`]**
* Ques. Second Highest Salary Per Department

```
WITH RankedSalaries AS (
  SELECT 
  Name, 
  Department, 
  Salary,
  DENSE_RANK() OVER(PARTITION BY Department ORDER BY Salary DESC) AS Salary_Rank
  FROM Employees
)

SELECT Name, Department, Salary
FROM RankedSalaries
WHERE Salary_Rank = 2;
```

* Ques. You are a Data Engineer at a FinTech company. The product team wants to build a new feature that shows users their transaction history, their running balance, and how much their spending changed compared to their last transaction.

* **The Table:** `Transactions`

| Txn_ID | Account_ID | Txn_Date | Amount |
| --- | --- | --- | --- |
| 1 | A100 | 2026-05-01 | 500 |
| 2 | A100 | 2026-05-02 | -50 |
| 3 | A100 | 2026-05-03 | 200 |
| 4 | B200 | 2026-05-01 | 1000 |

* **Your Task:**
Write a single SQL query that returns:

1. `Account_ID`
2. `Txn_Date`
3. `Amount`
4. `Running_Balance` (The cumulative sum of the amount for that specific account over time).
5. `Previous_Amount` (The amount of the transaction that happened right before this one, for that specific account).

How would you construct the `SELECT` statement using `SUM()` and `LAG()` to solve this?

```
WITH Helper AS(
  SELECT 
    Account_Id, 
    Txn_Date,
    Amount,
    SUM(Amount) OVER(PARTITION BY Account_ID ORDER BY Txn_Date) AS Running_Sum,
    LAG(Amount) OVER(PARTITION BY Account_ID ORDER BY Txn_Date) AS Previous_Amount
    FROM Transactions
)

SELECT Account_ID, Txn_Date, Amount, Running_Sum, Previous_Amount
FROM Helper; 
```



### Chunk 5: Performance Optimization & Architecture

**LIMIT & OFFSET**
* **LIMIT X:** Only Give X Rows
* **OFFSET Y:** Skip First Y Rows

```
SELECT Name, Salary
FROM Employees
ORDER BY Salary DESC
LIMIT 10 OFFSET 10
```

* Skips First 10 then gives next 10
* **Common Trap:** Is LIMIT 10 OFFSET 100000 fast? -> No because Database Physically read 100000 rows just to throw them away
  * We can also use WHERE id > 100000 LIMIT 10

**INDEXING [`VERY IMPORTANT`]**

* **Full Table Scan O(N):** Every Row 1 by 1

* **Index 2 Types: Clustered & Non-Clustered**

* **Clustered Index: (Change Physical Order of Rows)**
  * Physically Reorder Rows to match Index
  * Only 1 per table

* **Non-Clustered Index: (Don't Change Physical Order of Rows)**
  * Create seperate list of pointers to data
  * Multiple Allowed

* **INDEX TRAP:** If Index make reading fast, why not Index every column in database?
  * **ANSWER:** Index slows `WRITES`, everytime INSERT/DELETE/UPDATE (eg: 20 indexed columns) then database update every index then simple Insert operation becomes 20 + 1 operations. So, Only Index columns which are FREQUENTLY used.


**Stop `SELECT *`**
* Fetches Every Column Wasting Bandwidth
* Use: Select name, email (*only required columns fetch*)

**No Functions On Indexed Columns**

* **BAD CODE:** `YEAR(Hire_Date)` It fails because Function applied on Every Row (*Makes Index Useless*)
* **GOOD CODE:** `Hire_Date >= '2026-01-01 AND Hire_Date <='2027-01-01'` Database Engine use Index to directly jump to start Date


