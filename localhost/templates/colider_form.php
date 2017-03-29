
<form action="index.php" method="post">
    <fieldset>
        <div class="control-group">
            <input class="input-xxlarge" name="seed" type="text" placeholder="Seed Word or Phrase  (optional)">
            <input class="input-small" name="collisions" placeholder="Collisions" type="number" min="0" /> 
        </div>
        <div class="control-group">
            <select class="span2" name="v1">
                <option value=''>Word Form</option>
                <option value='v'>Verb</option>
                <option value='n'>Noun</option>
            </select>
            <select class="span2"name="v2">
                <option value=''>Word Form (opt)</option>
                <option value='v'>Verb</option>
                <option value='n'>Noun</option>
            </select>
        </div>
        <div class="control-group">
            <button type="submit" class="btn btn-large btn-primary">Think!</button>
        </div>
    </fieldset>
</form>

