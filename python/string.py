"""
s1: ropp##on#m
evaluated s1 : room
s2: r#rpp##oom
evaluated s2: room
"""

def parseStr(str): 
	t = str.find('#')
	if t == -1:
		return str
	else:
		return parseStr(str[:t-1] + str[t+1:])


