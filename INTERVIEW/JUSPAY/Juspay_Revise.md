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
