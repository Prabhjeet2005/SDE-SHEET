import requests
from bs4 import BeautifulSoup


def decode_secret_message(url):
    # 1. Add a browser User-Agent to bypass Google's automated blocks
    headers = {
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36"
    }

    # 2. Fetch the page with the headers included
    response = requests.get(url, headers=headers)
    soup = BeautifulSoup(response.text, "html.parser")

    # Find all table rows
    rows = soup.find_all("tr")

    # Safety check so the code doesn't crash if Google blocks it again
    if not rows:
        print(
            "Error: Could not find any table data. Google might be blocking the request, or the URL is invalid."
        )
        return

    # Dynamically find column indices by reading the header row (row 0)
    header = [cell.text.lower().strip() for cell in rows[0].find_all(["th", "td"])]

    x_idx, char_idx, y_idx = 0, 1, 2  # default fallbacks
    for i, col in enumerate(header):
        if "x" in col:
            x_idx = i
        elif "y" in col:
            y_idx = i
        elif "char" in col or "unicode" in col:
            char_idx = i

    grid_data = []
    max_x, max_y = 0, 0

    # Extract coordinates and characters from the remaining rows
    for row in rows[1:]:
        cells = row.find_all(["th", "td"])
        if len(cells) >= 3:
            try:
                x = int(cells[x_idx].text.strip())
                y = int(cells[y_idx].text.strip())
                char_text = cells[char_idx].text.strip()
                char = char_text if char_text else " "

                grid_data.append((x, y, char))
                max_x = max(max_x, x)
                max_y = max(max_y, y)
            except ValueError:
                continue  # Skip rows with invalid header data

    if not grid_data:
        print("Error: Table found, but no coordinate data could be extracted.")
        return

    # Initialize the 2D grid with space characters
    grid = [[" " for _ in range(max_x + 1)] for _ in range(max_y + 1)]

    # Populate the grid
    for x, y, char in grid_data:
        grid[y][x] = char

    # Print to console (iterating backwards to orient the y-axis correctly)
    for y in range(max_y, -1, -1):
        print("".join(grid[y]))


# Call the function
url = "https://docs.google.com/document/d/e/2PACX-1vSvM5gDlNvt7npYHhp_XfsJvuntUhq184By5xO_pA4b_gCWeXb6dM6ZxwN8rE6S4ghUsCj2VKR21oEP/pub"
decode_secret_message(url)
