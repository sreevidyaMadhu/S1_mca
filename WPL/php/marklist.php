<html>
    <head>
        <style>
    body {
      background-color: #F8F4EA;
      font-family: Arial, sans-serif;
      display: flex;
      justify-content: center;
      align-items: center;
      height: 100vh;
    }

    form {
      background-color: #FFFFFF;
      padding: 30px 40px;
      border-radius: 12px;
      text-align: center;
      width: 350px;
    }

    h1 {
      color: #5A2A83;
      margin-bottom: 20px;
    }
    </style>
    </head>
  <body>


    <form action="card.php" method="post">
      <h1>Student Details</h1><br>
      Enter your Name: <input type="text" name="name"><br><br>
      Enter your Roll no: <input type="text" name="rollno"><br><br>
      Enter your Age: <input type="text" name="age"><br><br>
      Enter your subject Marks:<br><br>
      English: <input type="text" id="m1" name="eng"><br><br>
      Hindi: <input type="text" id="m2" name="hindi"><br><br>
      Computer Science: <input type="text" id="m3" name="cs"><br><br>
      Elective: <input type="text" id="m4" name="elective"><br><br>

      <button type="button" onclick="calc()">Total Marks</button>
      <input type="submit" value="Submit">
      <p id="a"></p>
    </form>

    <script>
      function calc() {
        let m1 = parseInt(document.getElementById("m1").value);
        let m2 = parseInt(document.getElementById("m2").value);
        let m3 = parseInt(document.getElementById("m3").value);
        let m4 = parseInt(document.getElementById("m4").value);

        let total = m1 + m2 + m3 + m4;

        document.getElementById("a").innerHTML = "The total mark is: " + total;
      }
    </script>
  </body>
</html>


    