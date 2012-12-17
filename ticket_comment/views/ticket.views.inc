<?php



/**
 * Implements hook_views_default_views().
 */
function ticket_comment_views_default_views() {
  $views = array();
  
  $view = new view();
  $view->name = 'ticket_comments';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'ticket_comment';
  $view->human_name = 'Ticket Comments';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Ticket Comments';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer ticket comments';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Ticket comment: User uid */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'ticket_comment';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  /* Relationship: Ticket comment: Ticket ticket_id */
  $handler->display->display_options['relationships']['ticket']['id'] = 'ticket';
  $handler->display->display_options['relationships']['ticket']['table'] = 'ticket_comment';
  $handler->display->display_options['relationships']['ticket']['field'] = 'ticket';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'user';
  /* Field: Ticket: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'ticket';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'ticket';
  /* Field: Field: Body */
  $handler->display->display_options['fields']['ticket_body']['id'] = 'ticket_body';
  $handler->display->display_options['fields']['ticket_body']['table'] = 'field_data_ticket_body';
  $handler->display->display_options['fields']['ticket_body']['field'] = 'ticket_body';
  /* Field: Field: Importance */
  $handler->display->display_options['fields']['ticket_category_importance']['id'] = 'ticket_category_importance';
  $handler->display->display_options['fields']['ticket_category_importance']['table'] = 'field_data_ticket_category_importance';
  $handler->display->display_options['fields']['ticket_category_importance']['field'] = 'ticket_category_importance';
  /* Field: Field: State */
  $handler->display->display_options['fields']['ticket_category_state']['id'] = 'ticket_category_state';
  $handler->display->display_options['fields']['ticket_category_state']['table'] = 'field_data_ticket_category_state';
  $handler->display->display_options['fields']['ticket_category_state']['field'] = 'ticket_category_state';
  /* Field: Field: Assigned to */
  $handler->display->display_options['fields']['ticket_entity_reference_user']['id'] = 'ticket_entity_reference_user';
  $handler->display->display_options['fields']['ticket_entity_reference_user']['table'] = 'field_data_ticket_entity_reference_user';
  $handler->display->display_options['fields']['ticket_entity_reference_user']['field'] = 'ticket_entity_reference_user';
  $handler->display->display_options['fields']['ticket_entity_reference_user']['settings'] = array(
    'link' => 0,
  );
  /* Field: Ticket comment: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'ticket_comment';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Ticket comment: Date changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'ticket_comment';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'admin/structure/ticket-comments';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Ticket Comments';
  $handler->display->display_options['menu']['description'] = 'Manage ticket comments';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $translatables['ticket_comments'] = array(
    t('Master'),
    t('Ticket Comments'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('User'),
    t('Ticket'),
    t('Name'),
    t('Title'),
    t('Body'),
    t('Importance'),
    t('State'),
    t('Assigned to'),
    t('Date created'),
    t('Date changed'),
    t('Page'),
  );

  $views[] = $view;
  return $views;
}