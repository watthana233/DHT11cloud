# DHT11cloud

# กลุ่ม Parallel database DEW

# วงจรรวม
![alttext]
(https://github.com/watthana233/DHT11cloud/blob/master/dhtcloud.png)

#อุปกรณ์ที่ใช้

# DHT11
เป็นเซ็นเซอร์ที่ใช้วัดอุณหภูมิเป็นองศาเซลเซียล และองศาฟาเรนไฮ ยังสามารถวัดความชื้นได้อีกด้วย มีไลบารี่พร้อมใช่งานกับ Arduino หรือ Nodemcu สามารถใช้วัดค่าได้เที่ยงตรงกว่า NTC หรือ PTC มาก เพราะให้เอาต์พุตออกมาในรูปของดิจิตอล ใช้วัดอุณหภูมิอากาศโดยรอบ

![alttext]
(https://github.com/watthana233/DHT11cloud/blob/master/dht11.png)

# DHT11 มีทั้งหมดอยู่ 4 ขา คือ
ลำดับ ขาใช้งาน
1. VCC  (ไฟ +5v)
2. DATA
3. NC (ไม่ต่อก็ได้)
4. GND

# Soil Moisture Sensor Module
โมดูลนี้ใช้สำหรับวัดค่าความชื้นในดิน ให้ค่าออกเป็นแบบ Analog ถ้าต่อกับ บอร์ด Arduino หรือ Nodemcu จะได้ค่า 0-1023 ออกมาเขียนโปรแกรมเช็คเงื่อนไขให้ทำงาน และให้ค่าแบบ Digital เมื่อมีค่าถึงจุดที่กำหนดจะมีสัญญาณ 1 ออกมา สามารถปรับค่าความไวได้ที่โวลุ่มบนบอร์ด และหากใช้งานร่วมกับโมดูล Wifi เช่น ESP8266 ก็จะสามารถเขียนโปรแกรมให้แสดงผลผ่านทาง web และใช้สมาร์ทโฟนระบบ Android แสดงผลหรือสั่งงานได้ด้วย

![alttext]
(https://github.com/watthana233/DHT11cloud/blob/master/soil.jpg)

# Soil Moisture Sensor Module มีทั้งหมดอยู่ 4 ขา คือ
ลำดับ ขาใช้งาน
1. VCC  (ไฟ +5v)
2. GND
3. D0 (ขา digital)
4. A0 (ขา analog)

# 20x4 Character LCD Module
จอแสดงผล LCD ขนาด 20 ตัวอักษร 4 บรรทัด ใช้ไฟ 5 โวลต์ พร้อมไฟ blacklight เชื่อมต่อกับ Arduino หรือ Nodemcu ได้ง่ายใช้ library มาตรฐานพร้อมใช้งาน 

![alttext]
(https://github.com/watthana233/DHT11cloud/blob/master/lcd.png)

# 20x4 Character LCD Moduleมีทั้งหมดอยู่ 4 ขา คือ
ลำดับ ขาใช้งาน
1. VCC  (ไฟ +5v)
2. GND
3. SDA (D1)
4. SCL (D2)

# NodeMCU V2 LUA based ESP8266-12E NodeMCU V2
NodeMCU V2 ถูกพัฒนาให้สามารถใช้ร่วมกับ Arduino IDE และปรับปรุงให้มีขนาดเล็กกว่ Node MCU V1 บอร์ดมีขนาดเล็กลง บอร์ดกว้าง 2.5CM และใช้ Esp8266-12E มีเสาร์อากาศในตัว ใช้ชิฟ USB เบอร์ CP2102 ในการติดต่อกับคอมพิวเตอร์เพื่อโปรแกรม และสามารถใช้โปรแกรมได้หลากหลายภาษา ไม่ว่าจะเป็น AT Command ใช้ร่วมกับ Arduino ภาษา Lau และ การโปรแกรมด้วย Arduino IDE 
    
![alttext]
(https://github.com/watthana233/DHT11cloud/blob/master/nodemcu.png)


-----------------------------
สมาชิกกลุ่ม
1. นายบัณฑิต  วีระ 56523206053-5
2. นายรุ่งโรด โกสโล 56523206024-6
3. นาย วุฒิชัย อินทา 55543206117-7
4. นายกฤษณา  ไสยาสน์ 56523206003-0
5. นายวัฒนา  ปันโทธุ 57523206031-0

