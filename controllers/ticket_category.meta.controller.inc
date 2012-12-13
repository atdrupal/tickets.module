<?php

class TicketCategoryEntityMetaController extends EntityDefaultMetadataController {
  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();
    $properties = &$info[$this->type]['properties'];

    $properties['name'] = array(
      'label' => t('Name'),
      'description' => t('The ticket category name.'),
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer ticket category',
      'schema field' => 'name',
    );

    $properties['type'] = array(
      'type' => 'ticket',
      'getter callback' => 'entity_property_getter_method',
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer ticket category',
      'required' => TRUE,
      'description' => t('The ticket category type.'),
    ) + $properties['type'];

    unset($properties['uid']);

    $properties['user'] = array(
      'label' => t("User"),
      'type' => 'user',
      'description' => t("The owner of the ticket category."),
      'getter callback' => 'entity_property_getter_method',
      'setter callback' => 'entity_property_setter_method',
      'setter permission' => 'administer ticket category',
      'required' => TRUE,
      'schema field' => 'uid',
    );

    $properties['created'] = array(
      'label' => t("Date created"),
      'type' => 'date',
      'description' => t("The date the ticket category was created."),
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer ticket category',
      'schema field' => 'created',
    );
    $properties['changed'] = array(
      'label' => t("Date changed"),
      'type' => 'date',
      'schema field' => 'changed',
      'description' => t("The date the ticket category was most recently updated."),
    );

    return $info;
  }
}