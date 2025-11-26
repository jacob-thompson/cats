#!/usr/bin/env lua

local argc = #arg

local function usage()
  io.stderr:write("Usage: cat [file]\n")
  os.exit(1)
end

local function main()
  if argc > 1 then
    usage()
  end

  if argc == 1 then
    local filename = arg[1]
    local f, err = io.open(filename, "rb")
    if not f then
      io.stderr:write(string.format("%s: %s\n", filename, err))
      os.exit(1)
    end

    while true do
      local chunk = f:read(8192)
      if not chunk then break end
      local ok, werr = pcall(function() io.stdout:write(chunk) end)
      if not ok then
        io.stderr:write(string.format("%s: %s\n", filename, werr or "write error"))
        f:close()
        os.exit(1)
      end
    end

    f:close()
  else
    while true do
      local chunk = io.stdin:read(8192)
      if not chunk then break end
      local ok, werr = pcall(function() io.stdout:write(chunk) end)
      if not ok then os.exit(1) end
    end
  end

  return 0
end

local function handle_err(err)
  local msg = tostring(err)
  if msg:match("interrupted") then
    -- exit with 130 (128 + SIGINT)
    io.flush()
    os.exit(130)
  else
    io.stderr:write(msg .. "\n")
    io.flush()
    os.exit(1)
  end
end

local ok, rv = xpcall(main, handle_err)
if ok then io.flush(); os.exit(rv or 0) end
