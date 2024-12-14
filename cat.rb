require 'securerandom'

def generate_speech_bubble(message)
  bubble_width = message.length + 4
  top = "   " + "_" * bubble_width
  middle = "  / " + " " * (bubble_width - 2) + " \\"
  text = " |   " + message + "   |"
  bottom = "  \\ " + "_" * (bubble_width - 2) + " /"
  "#{top}\n#{middle}\n#{text}\n#{bottom}"
end

supportive_sentences = File.readlines('support.txt', chomp: true)
message = supportive_sentences.sample

cat = File.read('cat.txt')

puts generate_speech_bubble(message)
puts cat
