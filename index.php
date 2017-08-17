<!DOCTYPE html>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<meta http-equiv="Content-Type" content="text/html; charset=TIS-620">
<html>
<head>
    <title>DTH11</title>
    <?php  
        $conn = mysqli_connect("localhost", "root", "1234", "dht11");
        $temp = $_GET["temp"];
        $humi = $_GET["humi"];
        $heat = $_GET["heat"];
        $sql = "INSERT INTO esp8266 (temp, humi, heat) VALUES ($temp, $humi, $heat)";
        $query = $conn->query($sql);
    ?>
</head>
<body>
<table align="center" border="0" width="100%" height="100%" background="image/bg2.png">
<tr align="center">
    <td>
            <img src = "image/don.png">
            <img src = "image/hon.png">
            <img src = "image/ton.png">
    </td>
</tr>
<tr align="center">
    <td>
    <font face="TH Krub" size="5"><h2>อุณหภูมิ ณ เวลานี้</h2></font>
    <font face="Comic Sans MS" color="#FF3300" size="3">
    <h2>
        <?php
        	$conn = mysqli_connect("localhost", "root", "1234", "dht11");
            $sql = "SELECT * FROM esp8266 order by timeon DESC";
            $query = $conn->query($sql);
            $row = $query->fetch_assoc();
            echo "Temp : ".$row['temp']." &deg;C &nbsp; Humi : ".$row['humi']." &deg;C &nbsp; Heat : ".$row['heat']." &deg;F &nbsp; <br>".$row['timeon']."<br>";
        ?>
    </h2></font>
    </td>
</tr>
</table>
</body>
   <META HTTP-EQUIV='Refresh' CONTENT = '10;URL=index.php'>
</html>
