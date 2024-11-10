reset
set term gif animate
set terminal gif animate delay 50
set output "animation.gif"
n=8
i=0
load "script.p"
set output
