const
inf = 'minipaint.in'; inf = 'minipaint.in';
outf = 'minipaint.out'; outf = 'minipaint.out';
maxr = 50 + 10; maxr = 50 + 10;
maxc = 50 + 10; maxc = 50 + 10;
maxn = 3000 + 10; maxn = 3000 + 10;
oo = 1000000; oo = 1000000;

var var
ans, c, i, j, k, r, n : longint; ans, c, i, j, k, r, n: longint;
ch : char; ch: char;
a : array[0 .. maxr, 0 .. maxc] of longint; a: array [0 .. maxr, 0 .. maxc] of longint;
v1, v2, temp : array[0 .. maxn] of longint; v1, v2, temp: array [0 .. maxn] of longint;
v: array[0 .. maxc, 0 .. maxc] of longint; v: array [0 .. maxc, 0 .. maxc] of longint;

function min(a, b : longint) : longint; function min (a, b: longint): longint;
begin begin
if a < b then min := a else min := b; if a <b then min: = a else min: = b;
end; end;

function max(a, b : longint) : longint; function max (a, b: longint): longint;
begin begin
if a > b then max := a else max := b; if a> b then max: = a else max: = b;
end; end;

procedure work(x : longint); procedure work (x: longint);
var var
i, j, count : longint; i, j, count: longint;
begin begin
v[0][0] := 0; v [0] [0]: = 0;
for i := 1 to c do v[0][i] := oo; for i: = 1 to c do v [0] [i]: = oo;
temp[0] := 0; temp [0]: = 0;
for i := 1 to c do temp[i] := temp[i - 1] + a[x][i]; for i: = 1 to c do temp [i]: = temp [i - 1] + a [x] [i];
for i := 1 to c do for i: = 1 to c do
begin begin
for j := 0 to c do v[i][j] := oo; for j: = 0 to c do v [i] [j]: = oo;
v[i][0] := c; v [i] [0]: = c;
for j := 1 to i do for j: = 1 to i do
for k := 1 to i do for k: = 1 to i do
begin begin
count := min(temp[i] - temp[k - 1], (i - k + 1) - (temp[i] - temp[k - 1])); count: = min (temp [i] - temp [k - 1], (i - k + 1) - (temp [i] - temp [k - 1]));
v[i][j] := min(v[i][j], v[k - 1][j - 1] + count); v [i] [j]: = min (v [i] [j], v [k - 1] [j - 1] + count);
end; end;
end; end;
end; end;

begin begin
assign(input, inf); assign (input, inf);
assign(output, outf); assign (output, outf);
reset(input); reset (input);
rewrite(output); rewrite (output);
readln(r, c, n); readln (r, c, n);
for i := 1 to r do for i: = 1 to r do
begin begin
for j := 1 to c do for j: = 1 to c do
begin begin
read(ch); read (ch);
if ch = 'B' then a[i][j] := 0 else a[i][j] := 1; if ch = 'B' then a [i] [j]: = 0 else a [i] [j]: = 1;
end; end;
readln; readln;
end; end;
v2[0] := 0; v2 [0]: = 0;
for i := 1 to c do v2[i] := oo; for i: = 1 to c do v2 [i]: = oo;
for i := 1 to r do for i: = 1 to r do
begin begin
v1 := v2; v1: = v2;
for j := 0 to n do v2[j] := oo; for j: = 0 to n do v2 [j]: = oo;
work(i); work (i);
for j := 0 to n do for j: = 0 to n do
for k := 0 to c do for k: = 0 to c do
if j >= k then if j> = k then
v2[j] := min(v2[j], v1[j - k] + v[c][k]); v2 [j]: = min (v2 [j], v1 [j - k] + v [c] [k]);
end; end;
ans := oo; ans: = oo;
for j := 0 to n do ans := min(ans, v2[j]); for j: = 0 to n do ans: = min (ans, v2 [j]);
writeln(ans); writeln (ans);
close(input); close (input);
close(output); close (output);
end. end.
