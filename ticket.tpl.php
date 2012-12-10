<?php
    $content = $elements;
//    kpr($element);
?>
<h2><?php echo render($content->title); ?></h2>
<div class="content"<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content);
    ?>
</div>
