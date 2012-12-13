<?php

class TicketCommentEntityMetaController extends EntityDefaultMetadataController {
  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();
    $properties = &$info[$this->type]['properties'];
    
    unset($properties['ticket_id']);
    $properties['ticket'] = array(
      'label' => t('Ticket'),
      'type' => 'ticket',
      'description' => t('The ticket.'),
      'getter callback' => 'entity_property_getter_method',
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer ticket comments.',
      'schema field' => 'ticket_id',
    );

    $properties['type'] = array(
      'type' => 'ticket_comments',
      'getter callback' => 'entity_property_getter_method',
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer ticket comments category',
      'required' => TRUE,
      'description' => t('The ticket comments type.'),
    ) + $properties['type'];

    unset($properties['uid']);

    $properties['user'] = array(
      'label' => t("User"),
      'type' => 'user',
      'description' => t("The owner of the ticket comments."),
      'getter callback' => 'entity_property_getter_method',
      'setter callback' => 'entity_property_setter_method',
      'setter permission' => 'administer ticket comments',
      'required' => TRUE,
      'schema field' => 'uid',
    );

    $properties['created'] = array(
      'label' => t("Date created"),
      'type' => 'date',
      'description' => t("The date the ticket comments was created."),
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer ticket comments',
      'schema field' => 'created',
    );
    $properties['changed'] = array(
      'label' => t("Date changed"),
      'type' => 'date',
      'schema field' => 'changed',
      'description' => t("The date the ticket comments was most recently updated."),
    );

    return $info;
  }
}