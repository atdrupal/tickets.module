<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying edit links
 * as fields
 */


class ticket_handler_edit_link_field extends ticket_handler_link_field {
  function construct() {
    parent::construct();
    $this->additional_fields['type'] = 'type';
  }


  function render($values) {
    $type = $values->{$this->aliases['type']};
    
    //Creating a dummy ticket to check access against
    $dummy_ticket = (object) array('type' => $type);
    if (!ticket_access('edit', $dummy_ticket)) {
      return;
    }
    
    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    $ticket_id = $values->{$this->aliases['ticket_id']};
    
    return l($text, 'admin/content/tickets/ticket/' . $ticket_id . '/edit');
  }
}
