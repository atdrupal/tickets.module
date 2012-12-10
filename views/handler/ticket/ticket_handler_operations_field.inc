<?php

/**
 * This field handler aggregates operations that can be done on a ticket
 * under a single field providing a more flexible way to present them in a view
 */
class ticket_handler_ticket_operations_field extends views_handler_field {
  function construct() {
    parent::construct();

    $this->additional_fields['ticket_id'] = 'ticket_id';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {

    $links = menu_contextual_links('tickets', 'admin/structure/tickets/manage/', array($this->get_value($values, 'ticket_id')));
//    kpr(array($this->get_value($values, 'ticket_id')));exit;
    
    if (!empty($links)) {
      return theme('links', array('links' => $links, 'attributes' => array('class' => array('links', 'inline', 'operations'))));
    }
  }
}
