<?php
/**
 * View can see this properties
 */
class TicketEntityMetaController extends EntityDefaultMetadataController {
  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();
    $properties = &$info[$this->type]['properties'];

    $properties['title'] = array(
      'label' => t('Title'),
      'description' => t('The ticket title.'),
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer tickets',
      'schema field' => 'title',
    );

    $properties['type'] = array(
      'type' => 'ticket',
      'getter callback' => 'entity_property_getter_method',
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer tickets',
      'required' => TRUE,
      'description' => t('The ticket type.'),
    ) + $properties['type'];

    unset($properties['uid']);

    $properties['user'] = array(
      'label' => t("User"),
      'type' => 'user',
      'description' => t("The owner of the ticket."),
      'getter callback' => 'entity_property_getter_method',
      'setter callback' => 'entity_property_setter_method',
      'setter permission' => 'administer tickets',
      'required' => TRUE,
      'schema field' => 'uid',
    );

    $properties['weight'] = array(
      'label' => t("Ticket weight"),
      'type' => 'numeric',
      'description' => t("The ticket weight."),
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer tickets',
      'schema field' => 'weight',
    );
    $properties['created'] = array(
      'label' => t("Date created"),
      'type' => 'date',
      'description' => t("The date the ticket was created."),
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer tickets',
      'schema field' => 'created',
    );
    $properties['changed'] = array(
      'label' => t("Date changed"),
      'type' => 'date',
      'schema field' => 'changed',
      'description' => t("The date the ticket was most recently updated."),
    );

    return $info;
  }
}