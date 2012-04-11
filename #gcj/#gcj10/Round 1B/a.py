import sys, os
 
input = open('A-large.in','r')
output = open('A-large.out','w')
 
ncase = int( input.readline().rstrip() )
 
directory = {}
 
for testno in xrange(1,ncase+1):
	ret = 0
	N, M = map( int, input.readline().rstrip().split() )
	os.system('rm /home/hhjeong/gcj/tmp -rf')
	os.system('mkdir /home/hhjeong/gcj/tmp')
 
	print os.listdir( '/home/hhjeong/gcj/tmp/')
 
	for i in xrange(N):
		path = input.readline().rstrip().split('/')[1:]
		newpath = '/home/hhjeong/gcj/tmp'
		for x in path:
			newpath += '/' + x
			os.system( 'mkdir '+newpath )
 
	for i in xrange(M):
		path = input.readline().rstrip().split('/')[1:]
		newpath = '/home/hhjeong/gcj/tmp'
		for x in path:
			newpath += '/' + x
			print 'debug ', newpath
			if os.system( 'mkdir '+newpath ) == 0:
				print newpath
				ret += 1
	output.write('Case #%d: %d\n'%(testno,ret))	
input.close()
output.close()
