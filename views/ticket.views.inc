<?php

/**
 * @file
 * Providing extra functionality for the Ticket UI via views.
 */


/**
 * Implements hook_views_data()
 */
function ticket_views_data_alter(&$data) { 
  $data['ticket']['link_ticket'] = array(
    'field' => array(
      'title' => t('Link'),
      'help' => t('Provide a link to the ticket.'),
      'handler' => 'ticket_handler_link_field',
    ),
  );
  $data['ticket']['edit_ticket'] = array(
    'field' => array(
      'title' => t('Edit Link'),
      'help' => t('Provide a link to the edit form for the ticket.'),
      'handler' => 'ticket_handler_edit_link_field',
    ),
  );
  $data['ticket']['delete_ticket'] = array(
    'field' => array(
      'title' => t('Delete Link'),
      'help' => t('Provide a link to delete the ticket.'),
      'handler' => 'ticket_handler_delete_link_field',
    ),
  );
  // This content of this field are decided based on the menu structure that
  // follows tickets/ticket/%ticket_id/op
  $data['ticket']['operations'] = array(
    'field' => array(
      'title' => t('Operations links'),
      'help' => t('Display all operations available for this ticket.'),
      'handler' => 'ticket_handler_ticket_operations_field',
    ),
  );
}


/**
 * Implements hook_views_default_views().
 */
function ticket_views_default_views() {
  $views = array();

  $view = new view();
  $view->name = 'tickets';
  $view->description = 'A list of all tickets';
  $view->tag = 'tickets';
  $view->base_table = 'ticket';
  $view->human_name = 'Tickets';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Tickets';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'create any ticket type';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'ticket_id' => 'ticket_id',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'ticket_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Empty ';
  $handler->display->display_options['empty']['area']['content'] = 'No tickets have been created yet';
  /* Field: Ticket: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'ticket';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: Ticket: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'ticket';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Ticket: Link */
  $handler->display->display_options['fields']['link_ticket']['id'] = 'link_ticket';
  $handler->display->display_options['fields']['link_ticket']['table'] = 'ticket';
  $handler->display->display_options['fields']['link_ticket']['field'] = 'link_ticket';
  $handler->display->display_options['fields']['link_ticket']['label'] = 'View';
  /* Field: Ticket: Operations links */
  $handler->display->display_options['fields']['operations']['id'] = 'operations';
  $handler->display->display_options['fields']['operations']['table'] = 'ticket';
  $handler->display->display_options['fields']['operations']['field'] = 'operations';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'tickets_admin_page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'admin/content/tickets/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Tickets';
  $handler->display->display_options['tab_options']['description'] = 'Manage tickets';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

  $views[] = $view;
  return $views;

}
