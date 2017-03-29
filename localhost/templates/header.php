<!DOCTYPE html>

<html>

    <head>

        <link href="css/bootstrap.css" rel="stylesheet"/>
        <link href="css/bootstrap-responsive.css" rel="stylesheet"/>
        <link href="css/styles.css" rel="stylesheet"/>

        <?php if (isset($title)): ?>
            <title>GENIE: <?= htmlspecialchars($title) ?></title>
        <?php else: ?>
            <title>GENIE</title>
        <?php endif ?>

        <script src="js/jquery-1.8.2.js"></script>
        <script src="js/bootstrap.js"></script>
        <script src="js/scripts.js"></script>

    </head>

    <body>

        <div class="container-fluid">

            <div id="top">
                <div class="navbar navbar-inverse">
                    <div class="navbar-inner">
                        <a class="btn pull-right" href="#"><i class="icon-download-alt"></i></a>
                        <ul class="nav">
                            <li><a href="index.php">Start</a></li>
                            <li><a href="ht.php">How this Works</a></li>
                            <li><a href="w.php">Why do this?</a></li>
                            <li><a href="t.php">Tips</a></li>
                        </ul>
                    </div>
                </div>
                <a href="/"><img alt="GENIE Thought Extender" src="img/logo3.png"/></a>
                </br>
                <strong>Genie is an Extender Not an Imagination Engine</strong>
                </br>
                
                    
            </div>
            
            <div id="middle">

