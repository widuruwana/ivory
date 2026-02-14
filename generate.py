# generate.py

poem = """Dear,

I know I can be a handful sometimes,
And I am genuinely trying to do my best everyday,
Even though we both have our own distant worlds,
I realized mine is so much better with you in it,
Lets go for a hike together someday, just you and me,
And in a field of ivory grass, you can scratch my head,
Until I fall asleep against your chest,

I will love you forever.
<3

Love, Me."""

def get_instruction_path(start_val, target_val):
    """Calculates the sequence of instructions to get from start to target."""
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

def generate_optimized_esolang(text):
    # Start with a clean environment
    code_words = ["clear"] 
    current_val = 0

    for char in text:
        target_val = ord(char)
        
        # Calculate Path A: Mutate current value
        path_a = get_instruction_path(current_val, target_val)
        
        # Calculate Path B: Reset to 0 and build up
        path_b = ["forget"] + get_instruction_path(0, target_val)
        
        # The Optimizer: Choose the path with the fewest instructions
        if len(path_b) < len(path_a):
            code_words.extend(path_b)
        else:
            code_words.extend(path_a)
            
        # Output the character
        code_words.append("whisper")
        current_val = target_val

        # Temporal pacing for newlines
        if char == '\n':
            code_words.append("breathe")

    # Hardware interrupt at the end
    code_words.append("fade")
    return code_words

def format_output(words, words_per_line=10):
    lines = []
    for i in range(0, len(words), words_per_line):
        lines.append(" ".join(words[i:i + words_per_line]))
    return "\n".join(lines)

if __name__ == "__main__":
    # Generate the Valentine's Poem
    poem_code = generate_optimized_esolang(poem)
    with open("poem.ivy", "w") as f:
        f.write(format_output(poem_code, words_per_line=8))
    print(f"Optimized Poem: {len(poem_code)} instructions saved to poem.ivy")