## Q1 Rune Transformation Power
### 📝 Quick-Recall Cheat Sheet: String Segmenting & Reduction

**The Core Concept:**
When characters move and leave "dead" zones behind, stop looking at individual characters. **Group identical adjacent characters into contiguous blocks (segments).**

**The Mental Model:**

* **X Blocks = Targets** (`cSX`)
* **Y Blocks = Missiles** (`cSY`)
* **Rule of Engagement:** 1 Missile Block can only destroy 1 Target Block.

**The Implementation Trick (The `while` Loop):**
To group continuous characters, use an inner `while` loop inside your main `for` loop.

* **Crucial Step:** Always use `i--` immediately after the `while` loop so the outer `for` loop doesn't skip the next character.

**The 3-Step Decision Tree (The Final Output):**
Count your total 'X's (`cX`). Your goal is to return `cX` unless mathematically impossible.

1. **Enough Missiles? (`cSX <= cSY`):** You have enough Y blocks for every X block.
* *Result:* Destroy everything. Output = `cX`.


2. **Split Missiles? (`flg == true`):** You found at least one `YY` block. It can split left and right, acting as two missiles to save you.
* *Result:* Destroy everything. Output = `cX`.


3. **Forced Sacrifice (`else`):** You have more Targets than Missiles (e.g., `X Y X Y X`) and no `YY` to split. Exactly one X block *must* survive.
* *Result:* Sacrifice the smallest block to maximize points. Output = `cX - smallSeg`.


Here is the breakdown for the fourth question from the PDF.

## Question 4: The Kingdom's Rebellion (Create Adj_List if no Pointer given)

### 📝 Quick-Recall Cheat Sheet: Kingdom's Rebellion

**The OA Trap:**
Lengthy descriptions of "reassigning children" and "dynamic tree updates" are often **Red Herrings**.

**The Mental Model:**

* A parent's removal requires all its children to be rebels.
* Moving rebel children to a new parent does not change the mathematical truth of the tree.
* **Conclusion:** The problem is static. No simulation required.

**The Implementation Trick:**

1. Use `vector<vector<int>> adj` to store `adj[parent].push_back(child)`.
2. Loop `1` to `N` (handles the smallest index rule for free).
3. If node is a rebel `&&` no children are loyal -> Print it.

Does the "Red Herring" trap make sense here? Let me know if you want to trace a specific example before we move to Question 5!







