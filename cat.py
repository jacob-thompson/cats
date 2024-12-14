import random


def generate_speech_bubble(message):
    bubble_width = len(message) + 4
    top = "   " + "_" * bubble_width
    middle = f"  / {' ' * (bubble_width - 2)} \\"
    text = f" |   {message}   |"
    bottom = f"  \\ {'_' * (bubble_width - 2)} /"
    return f"{top}\n{middle}\n{text}\n{bottom}"


with open("support.txt") as f:
    supportive_sentences = f.read().strip().splitlines()

message = random.choice(supportive_sentences)

with open("cat.txt") as f:
    cat = f.read()

print(generate_speech_bubble(message))
print(cat)
