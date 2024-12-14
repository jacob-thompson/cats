math.randomseed(os.time())

CAT = "cat.txt"
SUPPORT = "support.txt"

local function file_exists(file)
    local f = io.open(file, "rb")
    if f then f:close() end
    return f ~= nil
end

local function line_count(file)
    local count = 0
    for _ in io.lines(file) do
        count = count + 1
    end
    return count
end

local function get_line(file, line_number)
    local index = 1
    for line in io.lines(file) do
        if index == line_number then
            return line
        end
        index = index + 1
    end
end

local function print_bubble(message, length)
    local bubble_length = length + 4

    -- print top of bubble
    print("   " .. string.rep("_", bubble_length))

    -- print middle of bubble
    print("  / " .. string.rep(" ", bubble_length - 2) .. " \\")

    -- print message
    print(" |   " .. message .. "   |")

    -- print bottom of bubble
    print("  \\ " .. string.rep("_", bubble_length - 2) .. " /")
end

local function print_cat()
    local file = io.open(CAT, "rb")
    if not file then return nil end
    local content = file:read "*a"
    file:close()
    print(content)
end

if not file_exists(SUPPORT) or not file_exists(CAT)then
    os.exit(1) -- exit with an error code
end

local random_line = math.random(1, line_count(SUPPORT))
local line = get_line(SUPPORT, random_line)
local line_length = string.len(line)

print_bubble(line, line_length)
print_cat()
