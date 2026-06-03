import pprint

data = {"z": 1, "a": 2, "b": {"nested_key": "value", "another": [1, 2, 3]}}

# Returns a formatted string
formatted_string = pprint.pformat(data, indent=4)

print(formatted_string)
