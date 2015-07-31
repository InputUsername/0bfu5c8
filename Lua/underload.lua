function r(p)local _,n=p:gsub("[()]","%0")if n
%2~=0 then print"Error: unmatched parentheses"
error()end local s={}local function e()if#s==0
then print("Error: empty stack")error()end end
local function u(v)s[#s+1]=v end function o()e
()local v=s[#s]s[#s]=nil return v end local i=
1 n=0 while#p>=i do local c=p:sub(i,i)if "~"==
c then a,b=o(),o()u(a)u(b)elseif":"==c then v=
o()u(v)u(v)elseif"!"==c then o()elseif c:byte(
)==42 local a,b=o(),o()push(b..a)elseif c=="("
then n=1 i=i+1 local v=""while true do local c
=string.sub(p,i,i)if c=="("then n=n+1 elseif c
==")"then n=n-1 end if n==0 then break end v=v
..c i=i+1 end u(v)elseif c=="a"then local v=o(
)u("("..v..")")elseif c=="^"then local v=o()p=
p:sub(1,i)..v..p:sub(i+1)elseif c=="S"then v=o
()io.write(v)end ip=ip+1 end end a={...}if#a<1
then print("Usage: "..a[0].." <-i | file>\nUs"
.."e -i to enter interactive mode")error()else
if a[1]=="-i"then while true do io.write("> ")
local p=io.read("*l")local x,y=pcall(r,p)if(x)
then print(y)end print("")end else local f=io.
open(a[1],"r")if not f then print("Error: cou"
.."ld not open "..a[1])error()end p=f:read"*a"
f:close()r(p)print()end end
