set ns [new Simulator]
$ns color 0 red
$ns color 1 blue
set repertoire "tcp.nam"
set f [open $repertoire w]
$ns namtrace-all $f
#fait la topologie
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
$ns make-lan "$n0 $n1" 10Mb 10ms LL Queue/DropTail Mac/802_3
$ns make-lan "$n2 $n3" 10Mb 10ms LL Queue/DropTail Mac/802_3
$ns at 10.0 "finish"
proc finish { } {
	global ns f repertoire
	$ns flush-trace
	close $f
	exec nam $repertoire &
	exit 0
}
$ns run