<?php

class EntityTicketUIController extends EntityDefaultUIController {
  /**
   * Provides definitions for implementing hook_menu().
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    //Define menu callback View mode ticket
    $items['ticket/%ticket'] = array(
      'title callback' => 'tickets_page_title',
      'title arguments' => array(1),
      'page callback' => 'tickets_page_view',
      'page arguments' => array(1),
      'access arguments' => array('access_content'),
      'type' => MENU_CALLBACK,
    );
    return $items;
  }

  public function overviewTable($conditions = array()) {
    $conditions['type'] = 'ticket';
    return parent::overviewTable($conditions);
  }
}

