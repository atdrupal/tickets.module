<?php kpr($elements);?>
<h2><?php echo render($elements->title); ?></h2>
<div class="content"<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($elements->content['comments']);
      print render($elements->content);
    ?>
    <?php print render($elements->content['comments']); ?>
</div>
