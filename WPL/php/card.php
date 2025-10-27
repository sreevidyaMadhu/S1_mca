<html><head><style>
    body {
      background-color: #F8F4EA;
      font-family: Arial, sans-serif;
      text-align: center;
      padding: 40px;
    }

    h1 {
      color: #5A2A83;
      margin-bottom: 20px;
    }

    table {
      margin: 0 auto;
      border-collapse: collapse;
      width: 60%;
      background-color: #FFFFFF;
      
    }
     th, td {
      padding: 10px;
      border: 1px solid #ccc;
      text-align: center;
    }
    
    th {
      background-color: #9D4EDD;
      color: white;
      padding: 12px;
      font-size: 18px;
      text-transform: uppercase;
    }

    td {
      padding: 10px;
      border: 1px solid #ddd;
      font-size: 16px;
    }

    .grade-pass {
      color: green;
      font-weight: bold;
    }

    .grade-fail {
      color: red;
      font-weight: bold;
    }

    </style>
    </head>
    <body>
        <h1>student grade card</h1>
<?php
$name = $_POST['name'];
$rollno = $_POST['rollno'];
$age = $_POST['age'];
$eng = $_POST['eng'];
$hindi = $_POST['hindi'];
$cs = $_POST['cs'];
$elective = $_POST['elective'];

$total = $eng + $hindi + $cs + $elective;
$avg = $total / 4;

if ($avg >= 90)
    $grade = "A+";
elseif ($avg >= 80)
    $grade = "A";
elseif ($avg >= 70)
    $grade = "B";
elseif ($avg >= 60)
    $grade = "C";
elseif ($avg >= 50)
    $grade = "D";
else
    $grade = "Fail";
?>

<table>
    <tr>
        <th colspan="2">Student Information</th>
    </tr>
    <tr>
        <td><b>Name</b></td>
        <td><?php echo $name; ?></td>
    </tr>
    <tr>
        <td><b>Roll No</b></td>
        <td><?php echo $rollno; ?></td>
    </tr>
    <tr>
        <td><b>Age</b></td>
        <td><?php echo $age; ?></td>
    </tr>

    <tr>
        <th colspan="2">Marks</th>
    </tr>
    <tr><td>English</td><td><?php echo $eng; ?></td></tr>
    <tr><td>Hindi</td><td><?php echo $hindi; ?></td></tr>
    <tr><td>Computer Science</td><td><?php echo $cs; ?></td></tr>
    <tr><td>Elective</td><td><?php echo $elective; ?></td></tr>

     <tr><td>Total Marks</td><td><?php echo $total; ?></td></tr>
    <tr><td>Average</td><td><?php echo round($avg, 2); ?></td></tr>
    <tr><td>Grade</td><td><?php echo $grade; ?></td></tr>
</table>
</body>
</html>



