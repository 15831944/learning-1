set ns [new Simulator]
set repertoire "udp.nam"
set f [open $repertoire w]
$ns namtrace-all $f
$ns color 0 blue
$ns color 1 red
$ns color 2 green
#faite la topology
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
$ns duplex-link $n0 $n2 1Mb 10ms DropTail
$ns duplex-link $n1 $n2 1Mb 10ms DropTail
$ns duplex-link $n2 $n3 1Mb 10ms SFQ
$ns duplex-link-op $n0 $n2 orient right-up
$ns duplex-link-op $n1 $n2 orient right-down
$ns duplex-link-op $n2 $n3 orient right
$ns duplex-link-op $n2 $n3 queuePos 0.5
#cree les sources et le traffic
set udp0 [new Agent/UDP]
set udp1 [new Agent/UDP]
$udp0 set class_ 0
$udp1 set class_ 1
$ns attach-agent $n0 $udp0
$ns attach-agent $n1 $udp1
set cbr0 [new Application/Traffic/CBR]
set cbr1 [new Application/Traffic/CBR]
$cbr0 set packetSize_ [expr 1*1024]
$cbr1 set packetSize_ [expr 1*1024]
$cbr0 set interval_ 15ms
$cbr1 set interval_ 15ms
$cbr0 attach-agent $udp0
$cbr1 attach-agent $udp1
set null0 [new Agent/Null]
$ns attach-agent $n3 $null0
#faites les conections
$ns connect $udp0 $null0
$ns connect $udp1 $null0
#temps pour les sources
$ns at 0.2 "$cbr0 start"
$ns at 0.3 "$cbr1 start"
$ns at 9.5 "$cbr0 stop"
$ns at 9.8 "$cbr1 stop"
$ns at 10.0 "finish"
proc finish { } {
	global ns f repertoire
	$ns flush-trace
	close $f
	exec nam $repertoire &
	exit 0
}
$ns run