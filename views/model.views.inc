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

  $view = new view;
  $view->name = 'tickets';
  $view->description = 'A list of all tickets';
  $view->tag = 'tickets';
  $view->base_table = 'ticket';
  $view->human_name = 'Tickets';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Tickets';
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
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Empty ';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No tickets have been created yet';
  /* Field: Ticket: Ticket ID */
  $handler->display->display_options['fields']['ticket_id']['id'] = 'ticket_id';
  $handler->display->display_options['fields']['ticket_id']['table'] = 'ticket';
  $handler->display->display_options['fields']['ticket_id']['field'] = 'ticket_id';
  $handler->display->display_options['fields']['ticket_id']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['ticket_id']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['ticket_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['ticket_id']['alter']['external'] = 0;
  $handler->display->display_options['fields']['ticket_id']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['ticket_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['ticket_id']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['ticket_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['ticket_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['ticket_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['ticket_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['ticket_id']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['ticket_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['ticket_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['ticket_id']['empty_zero'] = 0;
  /* Field: Ticket: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'ticket';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  /* Field: Ticket: Link */
  $handler->display->display_options['fields']['link_ticket']['id'] = 'link_ticket';
  $handler->display->display_options['fields']['link_ticket']['table'] = 'ticket';
  $handler->display->display_options['fields']['link_ticket']['field'] = 'link_ticket';
  $handler->display->display_options['fields']['link_ticket']['label'] = 'View';
  $handler->display->display_options['fields']['link_ticket']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['link_ticket']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['link_ticket']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['link_ticket']['alter']['external'] = 0;
  $handler->display->display_options['fields']['link_ticket']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['link_ticket']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['link_ticket']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['link_ticket']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['link_ticket']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['link_ticket']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['link_ticket']['alter']['html'] = 0;
  $handler->display->display_options['fields']['link_ticket']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['link_ticket']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['link_ticket']['hide_empty'] = 0;
  $handler->display->display_options['fields']['link_ticket']['empty_zero'] = 0;
  /* Field: Ticket: Operations links */
  $handler->display->display_options['fields']['operations']['id'] = 'operations';
  $handler->display->display_options['fields']['operations']['table'] = 'ticket';
  $handler->display->display_options['fields']['operations']['field'] = 'operations';
  $handler->display->display_options['fields']['operations']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['external'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['operations']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['operations']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['html'] = 0;
  $handler->display->display_options['fields']['operations']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['operations']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['operations']['hide_empty'] = 0;
  $handler->display->display_options['fields']['operations']['empty_zero'] = 0;
  
  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'tickets_admin_page');
  $handler->display->display_options['path'] = 'admin/content/tickets/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Tickets';
  $handler->display->display_options['tab_options']['description'] = 'Manage tickets';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';
  $translatables['tickets'] = array(
    t('Master'),
    t('Tickets'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Empty '),
    t('No tickets have been created yet'),
    t('Ticket ID'),
    t('.'),
    t(','),
    t('Name'),
    t('View'),
    t('Operations links'),
    t('Page'),
  );
  $views[] = $view;
  return $views;

}
