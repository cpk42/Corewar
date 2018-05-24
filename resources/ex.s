.name "tiny dong"
.comment "reeee"


#ld %184549376,r2
#sti r2,%4,%6

#ld 1,r2
#st r2,1

#ldi 20,%0,r2
#sti r2,0,%7
#live %1

#ldi 1,%0,r13
#sti r13,0,%7
#ldi 1,%0,r14
#sti r14,0,%7
#ldi 1,%0,r15
#sti r15,0,%7

#l2:	 sti r1,%:live,%1
#	and r1,%0,r1
#live:	 live %1
#	zjmp %:live

#live %1
#ld %2,r2
#sti r2,1,%1


#sti 23,45,%34
#sti r2,23,%34
	
#l2:	sti	r1,%:live,%0
#	and	r1,%0,r1
#live:	live	%1
#	zjmp	%:live
