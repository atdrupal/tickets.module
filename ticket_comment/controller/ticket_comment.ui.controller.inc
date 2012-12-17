<?php

class TicketCommentEntityUIController extends EntityDefaultUIController {
  /**
   * Provides definitions for implementing hook_menu().
   */
  public function hook_menu() {
    $items = parent::hook_menu();
//    kpr($items);exit;
//    $items['admin/structure/ticket-comments/manage/%entity_object/edit']['access callback'] = FALSE;
//    $items['admin/structure/ticket-comments/manage/%entity_object']['access callback'] = FALSE;
    unset($items['admin/structure/ticket-comments/manage/%entity_object/edit']);
    unset($items['admin/structure/ticket-comments/manage/%entity_object']);
//    unset($items['admin/structure/ticket-comments/manage/%entity_object/clone']);
    return $items;
  }

  public function overviewTable($conditions = array()) {
    $conditions['type'] = 'ticket_comment';
    return parent::overviewTable($conditions);
  }
}








