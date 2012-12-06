<?php

class TicketCategoryEntityUIController extends EntityDefaultUIController {
  /**
   * Provides definitions for implementing hook_menu().
   */
  public function hook_menu() {
    $items = parent::hook_menu();
//    kpr($items);exit;
//    // Overview
//    $items['admin/structure/tickets']
//      = $items['admin/structure/tickets/edit']
//      = $items['admin/structure/tickets'];
//    
//    
//    $items['admin/structure/tickets']['title']
//      = $items['admin/structure/tickets/edit']['title']
//      = t('Ticket');
//
//    // Entity add page
//    $items['ticket/add'] = $items['admin/structure/tickets/add'];
//    unset(
//      $items['admin/structure/tickets/add']['title callback'],
//      $items['admin/structure/tickets/add']['title arguments']
//    );
//    $items['ticket/add']['title'] = 'Create new Ticket';
//
//    $items['admin/structure/tickets/edit']['type'] = MENU_DEFAULT_LOCAL_TASK;

//    unset($items['admin/structure/langgo/machine']);
//    unset($items['admin/structure/langgo/machine/list']);
//    unset($items['admin/structure/langgo/machine/add']);
//
//    unset($items['admin/structure/langgo/machine/manage/%entity_object/clone']);

    return $items;
  }

  public function overviewTable($conditions = array()) {
    $conditions['type'] = 'ticket_category';
    return parent::overviewTable($conditions);
  }
}








