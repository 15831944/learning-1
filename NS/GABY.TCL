set ns [new Simulator]
$ns color 0 red
$ns color 1 blue
set repertoire "gaby.nam"
set f [open $repertoire w]
$ns namtrace-all $f
#fait la topologie
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
#cree les sources
set src0 [new Agent/TCP/FullTcp]
set src1 [new Agent/TCP/FullTcp]
set sink0 [new Agent/TCP/FullTcp]
set sink1 [new Agent/TCP/FullTcp]
$src0 set class_ 0
$src1 set class_ 1
$ns attach-agent $n0 $src0
$ns attach-agent $n1 $src1
$ns attach-agent $n3 $sink0
$ns attach-agent $n3 $sink1
$src0 set fid_ 0
$src1 set fid_ 0
$src0 set class_ 0
$src1 set class_ 1
$sink0 set fid_ 0
$sink1 set fid_ 0
$sink0 listen
$sink1 listen
$src0 set window_ 100
$src1 set window_ 100
#cree le traffic
set cbr0 [new Application/Traffic/My]
set cbr1 [new Application/Traffic/My]
$cbr0 set packetSize_ [expr 1*1024]
$cbr0 set internal_ 15ms
$cbr1 set packetSize_ [expr 1*1024]
$cbr1 set internal_ 15ms
$cbr0 attach-agent $src0
$cbr1 attach-agent $src1
#fait les conections
$ns connect $src0 $sink0
$ns connect $src1 $sink1
#temps pour la source
$ns at 0.2 "$cbr0 start"
$ns at 0.4 "$cbr1 start"
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