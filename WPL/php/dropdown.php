<?php
$con=mysqli_connect("localhost","root","","student");
if(!$con){
    echo "not connected";
}
$query="SELECT rollno FROM bio ORDER BY rollno";
$result=mysqli_query($con,$query);

if(isset($_POST['update'])){
    $rollno=$_POST['rollno'];
    $m1=$_POST['m1'];
    $m2=$_POST['m2'];
    $total=$m1+$m2;
    

    $update="UPDATE bio set mark1='$m1',mark2='$m2', Total='$total'WHERE Rollno='$rollno'";
    if (mysqli_query($con,$update)){
        echo"<script>alert('marks updated successfully');</script>";
    }
    else{
        echo"error in updating";
    }
}

$studdetails=null;
if(isset($_POST['show'])){
    $rollno=$_POST['rollno'];
    $sql="SELECT Rollno , name,mark1,mark2,Total FROM bio WHERE Rollno='$rollno'";
    $result1=mysqli_query($con,$sql);
    if(mysqli_num_rows($result1)>0){
        $studdetails=mysqli_fetch_assoc($result1);
    }else{
        echo "<p>roll no $rollno does not exist in the table</p>";
    }
}
?>

<html>
    <body bgcolor="beige">
        <center>
        <form action="" method="post">
            Select roll no:
            <select name="rollno" required>
                <?php
                while($row=mysqli_fetch_assoc($result))
                {
                    $roll=$row['rollno'];
                    echo"<option value='$roll'>$roll</option>";
                }
                ?>
                </select>
                <input type="submit" name="show"value="show details">
            </form>
            <?php if($studdetails): ?>
                <h2>Student details</h2>
                <form method="post" action="">
                    Roll no:<input type ="text" name="rollno" value="<?php echo $studdetails['Rollno'];?>" readonly>
                    Name:<input type ="text" name="name" value="<?php echo $studdetails['name'];?>" readonly>
                    Mark1:<input type ="text" name="m1" value="<?php echo $studdetails['mark1'];?>">
                    Mark2:<input type ="text" name="m2" value="<?php echo $studdetails['mark2'];?>">
                    
                    <input type="submit" name="update" value="update marks">
            
                </form>
                <?php endif ?>
            </body>
            </html>
