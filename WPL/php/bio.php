<?php
$name = $_POST['name'];
$rollno = $_POST['rollno'];
$m1=$_POST['m1'];
$m2=$_POST['m2'];
$gender=$_POST['gender'];
$total=$m1+$m2;
$con=mysqli_connect('localhost','root','','student');
if($con){
    echo "connected";
}
else{
    echo "not connected";
}

$quer1="select rollno from bio where rollno=$rollno";
$result=mysqli_query($con,$quer1);
if(mysqli_num_rows($result)>0){
   // while($row=mysqli_fetch_assoc($result))
        echo "<script>alert('roll no already exists');document.location='biodata.php'</script>";
    
}
else{
    $quer="insert into bio values('$name','$rollno','$gender','$m1','$m2','$total')";
    $insert=mysqli_query($con,$quer);
    if($insert){
   echo '<script>alert("inserted successfully");document.location="biodata.php";</script>';
}
}

?>