<?php

class EntityTicketUIController extends EntityDefaultUIController {
  /**
   * Provides definitions for implementing hook_menu().
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    return $items;
  }

  public function overviewTable($conditions = array()) {
    $conditions['type'] = 'ticket';
    return parent::overviewTable($conditions);
  }
}



