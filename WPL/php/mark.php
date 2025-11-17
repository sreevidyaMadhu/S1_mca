<?php
$name = $_POST['name'];
$rollno = $_POST['rollno'];
$mark=$_POST['mark'];
$con=mysqli_connect('localhost','root','','student');
if($con){
    echo "connected";
}
else{
    echo "not connected";
}
$query="insert into stud values('$rollno','$name','$mark')";
$insert=mysqli_query($con,$query);
if($insert){
   echo '<script>alert("inserted successfully");</script>';
}

?>