<?php

/**
 * @file
 * Builds placeholder replacement tokens for product-related data.
 */


/**
 * Implements hook_token_info().
 */
function tickets_token_info() {
  $type = array(
    'name' => t('Ticket'),
    'description' => t('Tokens related to individual products.'),
    'needs-data' => 'ticket',
  );

  // Tokens for products.
  $ticket = array();

  $ticket['ticket-id'] = array(
    'name' => t('Product ID'),
    'description' => t('The internal numeric ID of the product.'),
  );
  $ticket['type'] = array(
    'name' => t('Type'),
    'description' => t('The machine name of the product type.'),
  );
  $ticket['title'] = array(
    'name' => t('Title'),
    'description' => t('The title of the product.'),
  );

  // Chained tokens for products.
  $ticket['creator'] = array(
    'name' => t('Creator'),
    'description' => t('The creator of the product.'),
    'type' => 'user',
  );
  $ticket['created'] = array(
    'name' => t('Date created'),
    'description' => t('The date the product was created.'),
    'type' => 'date',
  );
  $ticket['changed'] = array(
    'name' => t('Date updated'),
    'description' => t('The date the product was last updated.'),
    'type' => 'date',
  );

  return array(
    'types' => array('ticket' => $type),
    'tokens' => array('ticket' => $ticket),
  );
}

/**
 * Implements hook_tokens().
 */
function ticket_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $url_options = array('absolute' => TRUE);

  if (isset($options['language'])) {
    $url_options['language'] = $options['language'];
    $language_code = $options['language']->language;
  }
  else {
    $language_code = NULL;
  }

  $sanitize = !empty($options['sanitize']);

  $replacements = array();

  if ($type == 'ticket' && !empty($data['ticket'])) {
    $ticket = $data['ticket'];

    foreach ($tokens as $name => $original) {
      switch ($name) {
        // Simple key values on the product.
        case 'ticket-id':
          $replacements[$original] = $ticket->product_id;
          break;

        case 'type':
          $replacements[$original] = $sanitize ? check_plain($ticket->type) : $ticket->type;
          break;

        case 'title':
          $replacements[$original] = $sanitize ? check_plain($ticket->title) : $ticket->title;
          break;

        // Default values for the chained tokens handled below.
        case 'creator':
          if (!$ticket->uid) {
            $name = variable_get('anonymous', t('Anonymous'));
          }
          else {
            $creator = user_load($ticket->uid);
            $name = $creator->name;
          }
          $replacements[$original] = $sanitize ? filter_xss($name) : $name;
          break;
        case 'created':
          $replacements[$original] = format_date($ticket->created, 'medium', '', NULL, $language_code);
          break;

        case 'changed':
          $replacements[$original] = format_date($ticket->changed, 'medium', '', NULL, $language_code);
          break;
      }
    }

    if ($creator_tokens = token_find_with_prefix($tokens, 'creator')) {
      $creator = user_load($ticket->uid);
      $replacements += token_generate('user', $creator_tokens, array('user' => $creator), $options);
    }

    foreach (array('created', 'changed') as $date) {
      if ($created_tokens = token_find_with_prefix($tokens, $date)) {
        $replacements += token_generate('date', $created_tokens, array('date' => $ticket->{$date}), $options);
      }
    }
  }

  return $replacements;
}
