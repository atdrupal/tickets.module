<?php

class TicketCommentEntityUIController extends EntityDefaultUIController {
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
//    $items['ticket-category/%ticket_category'] = array(
//      'title callback' => 'tickets_category_page_title',
//      'title arguments' => array(1),
//      'page callback' => 'tickets_category_page_view',
//      'page arguments' => array(1),
//      'access arguments' => array('access_content'),
//      'type' => MENU_CALLBACK,
//    );
    return $items;
  }

  public function overviewTable($conditions = array()) {
    $conditions['type'] = 'ticket_comments';
    return parent::overviewTable($conditions);
  }
}








