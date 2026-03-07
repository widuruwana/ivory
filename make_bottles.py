def get_instruction_path(start_val, target_val):
    moves = []
    diff = target_val - start_val
    tens = abs(diff) // 10
    ones = abs(diff) % 10
    
    if diff > 0:
        moves.extend(["passion"] * tens)
        moves.extend(["adore"] * ones)
    elif diff < 0:
        moves.extend(["heartbreak"] * tens)
        moves.extend(["miss"] * ones)
    return moves

def generate_string(text):
    code_words = ["forget"] # Clear the workspace cell
    current_val = 0
    for char in text:
        target_val = ord(char)
        path_a = get_instruction_path(current_val, target_val)
        path_b = ["forget"] + get_instruction_path(0, target_val)
        
        if len(path_b) < len(path_a):
            code_words.extend(path_b)
        else:
            code_words.extend(path_a)
            
        code_words.append("whisper")
        current_val = target_val
    return code_words

def format_output(words, words_per_line=8):
    lines = []
    for i in range(0, len(words), words_per_line):
        lines.append(" ".join(words[i:i + words_per_line]))
    return "\n".join(lines)

# The Ivory Program Structure
ivory_code = []

# Initialize Cell 0 to 99
ivory_code.extend(["clear", "forget"])
ivory_code.extend(["passion"] * 9)
ivory_code.extend(["adore"] * 9)

# Start the loop
ivory_code.append("promise")

# Print the current number
ivory_code.append("confess")

# Move to Cell 1, print lyric, move back to Cell 0
ivory_code.append("hold")
ivory_code.extend(generate_string("bottles of beer on the wall,\n"))
ivory_code.append("release")

# Print the current number again
ivory_code.append("confess")

# Move to Cell 1, print lyric, move back to Cell 0
ivory_code.append("hold")
ivory_code.extend(generate_string("bottles of beer.\nTake one down, pass it around,\n"))
ivory_code.append("release")

# Decrement the counter in Cell 0
ivory_code.append("miss")

# Print the new number
ivory_code.append("confess")

# Move to Cell 1, print lyric, move back to Cell 0
ivory_code.append("hold")
ivory_code.extend(generate_string("bottles of beer on the wall.\n\n"))
ivory_code.append("release")

# End the loop and fade out
ivory_code.extend(["always", "fade"])

# Format and write to file
final_code = format_output(ivory_code, words_per_line=8)
with open("99_bottles.ivy", "w") as f:
    f.write(final_code)

print("Successfully generated beautifully formatted 99_bottles.ivy!")