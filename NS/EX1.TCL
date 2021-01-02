set ns [new Simulator]
set nf [open ex1.nam w]
$ns namtrace-all $nf
set n0 [$ns node]
set n1 [$ns node]
$ns duplex-link $n0 $n1 2Mb 10ms DropTail
$ns duplex-link-op $n0 $n1 orient right
#Cree un agent UPD et liasion a node 0
set udp0 [new Agent/UDP]
$ns attach-agent $n0 $udp0
set cbr0 [new Application/Traffic/CBR]
$cbr0 set packetSize_ [expr 10*1024]
$cbr0 set interval_ 50ms
$cbr0 attach-agent $udp0
#Pour le recepteur
set null0 [new Agent/Null]
$ns attach-agent $n1 $null0
$ns connect $udp0 $null0
$ns at 0.2 "$cbr0 start"
$ns at 9.8 "$cbr0 stop"
proc finish { } {
	global ns nf
	$ns flush-trace
	close $nf
	exec nam ex1.nam &
	exit 0
}
$ns at 10.0 "finish"
$ns run