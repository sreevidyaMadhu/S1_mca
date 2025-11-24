<!DOCTYPE html>
<html>
<head>
    <title>View progress card</title>
</head>
<body bgcolor="lightcyan">
<center>
    <h2>SEARCH PROGRESS CARD</h2>
    <form method="POST">
    Enter Roll No: <input type="text" name="rollno" required>
    <input type="submit" value="View Progress Card" name="progresscard">
</form>
    


<?php
$conn = mysqli_connect("localhost", "root", "", "student");
if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

if (isset($_POST['progresscard'])) {

    $rollno = $_POST['rollno'];

    // FIXED QUERY
    $query = "SELECT name, Rollno, Gender, mark1, mark2, Total 
              FROM bio 
              WHERE Rollno = '$rollno'";

    $result = mysqli_query($conn, $query);

    if ($result && mysqli_num_rows($result) > 0) {
        $row = mysqli_fetch_assoc($result);
        $total = $row['Total'];

        // ⭐ Grade Calculation
        if ($total >= 90) {
            $grade = "A+";
        } elseif ($total >= 80) {
            $grade = "A";
        } elseif ($total >= 70) {
            $grade = "B+";
        } elseif ($total >= 60) {
            $grade = "B";
        } elseif ($total >= 50) {
            $grade = "C";
        } else {
            $grade = "Fail";
        }

        echo "<h3>PROGRESS CARD</h3>";
        echo "<table border='1' cellpadding='10'>";
        echo "<tr><td>Name</td><td>" . $row['name'] . "</td></tr>";
        echo "<tr><td>Roll No</td><td>" . $row['Rollno'] . "</td></tr>";
        echo "<tr><td>Gender</td><td>" . $row['Gender'] . "</td></tr>";
        echo "<tr><td>Mark 1</td><td>" . $row['mark1'] . "</td></tr>";
        echo "<tr><td>Mark 2</td><td>" . $row['mark2'] . "</td></tr>";
        echo "<tr><td>Total</td><td>" . $row['Total'] . "</td></tr>";
        echo "<tr><td>Grade</td><td><b>" . $grade . "</b></td></tr>";
        echo "</table>";
    } else {
        echo "<p>No record found for Roll No: $rollno</p>";
    }
}
?>

<br><br>


</center>
</body>
</html>

