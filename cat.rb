#!/usr/bin/env ruby

if ARGV.length > 1
  STDERR.puts "Usage: cat [file]"
  exit 1
end

STDIN.binmode
STDOUT.binmode

if ARGV.length == 1
  begin
    File.open(ARGV[0], "rb") { |f| IO.copy_stream(f, STDOUT) }
  rescue => e
    STDERR.puts "#{ARGV[0]}: #{e.message}"
    exit 1
  end
else
  IO.copy_stream(STDIN, STDOUT)
end
