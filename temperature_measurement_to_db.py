import os
import glob
import time
import datetime
import MySQLdb as mdb

os.system('modprobe w1-gpio')
os.system('modprobe w1-therm')

base_dir = '/sys/bus/w1/devices/'
device_folder = glob.glob(base_dir + '28*')[0]
device_file = device_folder + '/w1_slave'

def read_temp_raw():
    f = open(device_file, 'r')
    lines = f.readlines()
    f.close()
    return lines

def read_temp():
    lines = read_temp_raw()
    while lines[0].strip()[-3:] != 'YES':
        time.sleep(10)
        lines = read_temp_raw()
    equals_pos = lines[1].find('t=')
    if equals_pos != -1:
        temp_string = lines[1][equals_pos+2:]
        temp_c = float(temp_string) / 1000.0
      ### temp_f = temp_c * 9.0 / 5.0 + 32.0
        return temp_c    ###, temp_f
	
while True:

    try:
        time.sleep(5*60)
	pi_temp = read_temp()
        dtime = datetime.datetime.now()
        ### ans_time = time.mktime(dtime.timetuple())
        print "datetime  : %s temp : %s" % (dtime, pi_temp)
	con = mdb.connect('localhost', 'logger', 'password', 'temperatures');	
	cur = con.cursor()
        cur.execute("""INSERT INTO temperaturedata(dateandtime, temperature) VALUES(%s, %s)""", (dtime, pi_temp))
	con.commit()

    except mdb.Error, e:
        con.rollback()
        print "Error %d: %s" % (e.args[0],e.args[1])
	sys.exit(1)

    finally:
	if con:
	    con.close()

time.sleep(10)



























