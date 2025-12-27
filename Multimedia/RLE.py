print("Sandeep Shrestha")
def rle_compress(data):
    if not data:
        return ""
    
    compressed = []
    count = 1
    prev_char = data[0]
    
    for char in data[1:]:
        if char == prev_char:
            count += 1
        else:
            compressed.append(f"{count}{prev_char}")
            prev_char = char
            count = 1
    compressed.append(f"{count}{prev_char}")  # Add last run
    return "".join(compressed)

def rle_decompress(compressed):
    decompressed = []
    count_str = ""
    for char in compressed:
        if char.isdigit():
            count_str += char
        else:
            decompressed.append(char * int(count_str))
            count_str = ""
    return "".join(decompressed)

# Sample Data
original_data = "AAAABBBCCDAA"

# Compression
compressed_data = rle_compress(original_data)
print(f"Original Data: {original_data}")
print(f"Compressed Data: {compressed_data}")

# Decompression
decompressed_data = rle_decompress(compressed_data)
print(f"Decompressed Data: {decompressed_data}")
