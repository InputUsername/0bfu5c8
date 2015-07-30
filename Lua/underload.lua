local function run(code)local _,count=string.gsub(code,"[()]","%0")if
count%2~=0 then print("Error: unmatched parentheses")error()end local
stack={}local function check_empty()if#stack==0 then print("Error:"..
"empty stack")error()end end	local function push(value)stack[#stack+
1]=value end local function pop()check_empty()local val=stack[#stack]
stack[#stack]=nil return val end local ip=1 local n=0 while ip<=#code
do local c=string.sub(code,ip,ip)if c=="~"then local fst,second=pop()
,pop()push(fst)push(second)elseif c==":"then local val=pop()push(val)
push(val)elseif c=="!"then pop()elseif c=="*"then local first,second=
pop(),pop()push(second..first)elseif c=="("then n=1 ip=ip+1 local val
=""while not nil do local c=string.sub(code,ip,ip)if c=="("then n=n+1
elseif c==")"then n=n-1 end if n==0 then break end val=val..c ip=ip+1
end push(value)elseif c=="a"then local v=pop()push("("..v..")")elseif
c=="^"then local value=pop()code=string.sub(code,1,ip)..value..string
.sub(code,ip+1)elseif c=="S"then local v=pop()io.write( v)end ip=ip+1
end end if#arg<1 then print("Usage: "..arg[0].." <-i | file>\nUse -i"
.."to enter interactive mode")error()elseif arg[1]=="-i"then while 10
do io.write("> ")local c=io.read("*l")local r,er=pcall(run,c)if not r
then print(err)end print()end else local fi=io.open(arg[1],"r")if not
fi then print("Error: could not open "..arg[1])end local code=fi:read
("*a")fi:close()run(code)print()end
