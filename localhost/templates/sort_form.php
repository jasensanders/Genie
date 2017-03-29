
<form action="http://www.google.com/search" method="get">
    <fieldset>
        <div class="control-group">
            <?php
                $output1 = $_SESSION['output'];
                echo '<select name="q">';
                
                    print("<option value=''>Select Results</option>");          
           
                    foreach($output1 as $term) 
                    {
                        print("<option value =\"{$term}\">{$term}</option>");
                    }
                
                print("</select>")
                
            ?>
            <button type="submit" class="btn"><strong>Search Google!</strong></button>
        </div>
   </fieldset>
</form>
<form action="http://www.bing.com/search" method="get">
    <fieldset>
        <div class="control-group">
           <?php
                $output1 = $_SESSION['output'];
                print("<select name='q'>");
                
                    print("<option value=''>Select Results</option>");          
           
                    foreach($output1 as $term) 
                    {
                        print("<option value =\"{$term}\">{$term}</option>");
                    }
                
                print("</select>")
            ?>
            <button type="submit" class="btn btn-warning"><strong>Search Bing!</strong></button>
        </div>
        </fieldset>
</form>
<form action="http://search.ebay.com/search/search.dll" method="get">
    <fieldset>
        <div class="control-group">
        <input type="hidden" name="fts" value="2" />
        <input type="hidden" name="from" value="R40" />
        <input type="hidden" name="_trksid" value="m37" />

           <?php
                $output1 = $_SESSION['output'];
                print("<select name='satitle'>");
                
                    print("<option value=''>Select Results</option>");          
                    
                    foreach($output1 as $term) 
                    {
                        print("<option value =\"{$term}\">{$term}</option>");
                    }
                
                print("</select>")
            ?>
            <button type="submit" class="btn btn-success" value="Search"><strong>Search eBay!</strong></button>
        </div>
        </fieldset>
</form> 
<form action="https://pinterest.com/search/pins/" method="get">
    <fieldset>
        <div class="control-group">
           <?php
                $output1 = $_SESSION['output'];
                print("<select name='q'>");
                
                    print("<option value=''>Select Results</option>");          
           
                    foreach($output1 as $term) 
                    {
                        print("<option value =\"{$term}\">{$term}</option>");
                    }
                
                print("</select>")
            ?>
            <button type="submit" class="btn btn-danger"><strong>Search Pinterest!</strong></button>
        </div>
        </fieldset>
</form> 
<form action="http://www.amazon.com/exec/obidos/external-search" method="get">
    <fieldset>
        <div class="control-group">
           <?php
                $output1 = $_SESSION['output'];
                print("<select name='k'>");
                
                    print("<option value=''>Select Results</option>");          
           
                    foreach($output1 as $term) 
                    {
                        print("<option value =\"{$term}\">{$term}</option>");
                    }
                
                print("</select>")
            ?>
            <button type="submit" class="btn btn-inverse"><strong>Search Amazon!</strong></button>
        </div>
        </fieldset>
</form> 
<form action="http://www.youtube.com/results" method="get">
    <fieldset>
        <div class="control-group">
           <?php
                $output1 = $_SESSION['output'];
                print("<select name='search_query'>");
                
                    print("<option value=''>Select Results</option>");          
           
                    foreach($output1 as $term) 
                    {
                        print("<option value =\"{$term}\">{$term}</option>");
                    }
                
                print("</select>")
            ?>
            <button type="submit" class="btn btn-primary"><strong>Search YouTube!</strong></button>
        </div>
        </fieldset>
</form>       

