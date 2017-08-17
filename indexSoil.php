<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="Content-Type" content="text/html; charset=TIS-620">
    <title>SOIL</title>
    <?php  
        $conn = mysqli_connect("localhost", "root", "1234", "soil");
        $percent = $_GET["percent"];
        $data = $_GET["data"];
        $sql = "INSERT INTO moisture (percent, data) VALUES ($percent, $data)";
        $query = $conn->query($sql);
    ?>

</head>

<body bgcolor="#CCFFFF">
<table width="80%" height="100%" border="0" align="center"  bgcolor="#CCFFFF">
    <tr>
    <td colspan="2">
        <div align="center">
        <header><h1>การวัดค่าความชื้นของดินในช่วง 0-1024</h1></header>
        </div>
        <div>
        <font face="TH Niramit AS">
            <h4>ค่าความชื้นที่มีค่า 0-700 หรือมากกว่านั้น เป็นค่าที่อ่านได้จากการวัดความชื้นดินแบบทางอ้อม โดยใช้เครื่องมืออิเลคทรอนิกส์วัดการต้านทานไฟฟ้าหรือการนำไฟฟ้าของน้ำในดิน แล้วแปลงเป็นค่าของปริมาณของน้ำในดินมีหน่วยวัดเป็นมิลลิโวลล์ (mv) หรืออาจอ่านค่าเป็นร้อยละโดยปริมาตร</h4></font>
        </div>
    </td>
    <tr>
    <td width="20%">
       
    </td>
    <td width="60%" align="center" background="so.png" style="color:#8B4513;">
        <font face="TH Niramit AS" size="5">
        <h1>
            <?php
            $sql = "SELECT * FROM moisture order by timeon DESC";
            $query = $conn->query($sql);
            $row = $query->fetch_assoc();
                if ($row['data']<=490) {
                    echo "ดินแห้ง";
                } else if($row['data']>=500&&$row['data']<=700){
                    echo "ดินอุดมสมบูรณ์";
                } else{
                    echo "ดินเปียก";
                }
            ?>
        </h1>
        <h3>เปอร์เซ็นความชื้นในดิน</h3></font>
        <font face="Comic Sans MS">
        <h3>% Moisture = (Soil Moisture/1024) x 100</h3>
        <h4>
            <?php
            $sql = "SELECT * FROM moisture order by timeon DESC";
            $query = $conn->query($sql);
            $row = $query->fetch_assoc();
            echo "Soil Moisture : ".$row['percent']." % ";
            ?>
        </h4>

        <h3>
            <?php
            $sql = "SELECT * FROM moisture order by timeon DESC";
            $query = $conn->query($sql);
            $row = $query->fetch_assoc();
            echo "Soil Moisture : ".$row['data']." mv. <br> Date : ".$row['timeon']."<br>";
            ?>
        </h3></font>
    </td>
    </tr>
</body>
</body>
    <META HTTP-EQUIV='Refresh' CONTENT = '10;URL=index.php'>
</html>