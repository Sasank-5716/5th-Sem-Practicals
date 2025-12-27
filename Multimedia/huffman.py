import heapq
from collections import defaultdict

print("Sandeep Shrestha")
class HuffmanNode:
    def __init__(self, char=None, freq=0):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None

    def __lt__(self, other):
        return self.freq < other.freq

def build_frequency_dict(data):
    frequency = defaultdict(int)
    for char in data:
        frequency[char] += 1
    return frequency

def build_huffman_tree(frequencies):
    heap = []
    for char, freq in frequencies.items():
        heapq.heappush(heap, (freq, id(HuffmanNode()), HuffmanNode(char, freq)))
    
    while len(heap) > 1:
        freq1, _, node1 = heapq.heappop(heap)
        freq2, _, node2 = heapq.heappop(heap)
        
        merged = HuffmanNode(freq=node1.freq + node2.freq)
        merged.left = node1
        merged.right = node2
        
        heapq.heappush(heap, (merged.freq, id(merged), merged))
    
    return heap[0][2]

def generate_codes(root, current_code="", codes={}):
    if root is None:
        return
    
    if root.char is not None:
        codes[root.char] = current_code
        return
    
    generate_codes(root.left, current_code + "0", codes)
    generate_codes(root.right, current_code + "1", codes)
    return codes

def huffman_encode(data):
    frequencies = build_frequency_dict(data)
    huffman_tree = build_huffman_tree(frequencies)
    codes = generate_codes(huffman_tree)
    
    encoded_data = ''.join([codes[char] for char in data])
    return encoded_data, codes

# Example usage for multimedia data compression
if __name__ == "__main__":
    sample_data = "ABRACADABRA"
    encoded, code_table = huffman_encode(sample_data)
    
    original_bits = len(sample_data) * 8
    compressed_bits = len(encoded)
    compression_ratio = compressed_bits / original_bits
    
    print(f"Original Data: {sample_data}")
    print(f"Encoded Data: {encoded}")
    print("\nHuffman Code Table:")
    for char, code in code_table.items():
        print(f"{char}: {code}")
    print(f"\nCompression Ratio: {compression_ratio:.2%}")
