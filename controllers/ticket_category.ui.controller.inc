<?php

class TicketCategoryEntityUIController extends EntityDefaultUIController {
  /**
   * Provides definitions for implementing hook_menu().
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    return $items;
  }

  public function overviewTable($conditions = array()) {
    $conditions['type'] = 'ticket_category';
    return parent::overviewTable($conditions);
  }
}








