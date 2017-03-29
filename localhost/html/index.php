<?php

    // configuration
    require("../includes/config.php");
    // If form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["collisions"]))
        {
            apologize("Please mark number of thoughts to generate");
        }
        // if we just want a random thought with no seed
        else if (empty($_POST["seed"]))
        {
            if(empty($_POST["v1"])|| empty($_POST["v2"]))
            {
                apologize("In order to generate a random thought with no seed you must pick two parts of speech");
            }
            else
            {
                $argv1= $_POST["v1"]; 
                $argv2 = $_POST["v2"];
                $n = $_POST["collisions"];
                $output = array();
                $seed = "0";
                
                exec("~/vhosts/localhost/bin/colider {$n} {$argv1} {$argv2} {$seed}", $output);
                //$output = str_replace(" ", "+", $output);
                $_SESSION['output'] = $output; 
                
                render("sort_form.php", ["title" => "Sort", "output" =>$output]);   
            }
            //2 words per collision N number of collisions
         }
         //call speller and collider according to form submission
         //Either Display results directly or use call to get to search for results
         //otherwise render dsiplay page with results of colider
       else if (!empty($_POST["seed"]))
       {
            if(empty($_POST["v1"]))
            {
                apologize("In order to generate a random thought with a seed you must pick at least one part of speech");
            }
            else
            {
                $argv1= $_POST["v1"]; 
                $argv2 = "x";
                $n = $_POST["collisions"];
                $output = array();
                $seed = $_POST["seed"];
                $seed = str_replace (" ", "_", $seed);
                $valid = array();
                
                exec("~/vhosts/localhost/bin/spellcheck {$seed}", $valid);
                
                
                if(strcmp($valid[0],"true")==0)
                {
                
                    exec("~/vhosts/localhost/bin/colider {$n} {$argv1} {$argv2} {$seed}", $output); 
                    
                    $_SESSION['output'] = $output;
                    
                  
                    render("sort_form.php", ["title" => "Sort", "output" =>$output]);  
                }
                else
                {
                    apologize("Please check your spelling and make sure you are typing real words");
                }
            }
       }
    }
    else
    {
    // render colider_form cause they havent filled it out
    render("colider_form.php", ["title" => "Genie"]);
    }

?>
