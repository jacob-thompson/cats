const std = @import("std");

pub fn main() !void {
    const gpa = std.heap.page_allocator;
    const stdout = std.io.getStdOut().writer();
    const stdin = std.io.getStdIn().reader();

    var buffer: [4096]u8 = undefined;
    while (true) {
        const n = try stdin.read(&buffer);
        if (n == 0) break;
        try stdout.writeAll(buffer[0..n]);
    }
}
